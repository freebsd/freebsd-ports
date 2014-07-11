--- ./source/isl/domain.c.orig	2013-10-11 04:27:03.000000000 -0300
+++ ./source/isl/domain.c	2014-07-07 20:50:52.000000000 -0300
@@ -7,7 +7,11 @@
 #include <isl/list.h>
 #include <isl/constraint.h>
 #include <isl/ilp.h>
+#include <isl/lp.h>
 #include <isl/aff.h>
+#include <isl/map.h>
+#include <isl/val.h>
+#include <isl/val_gmp.h>
 
 #ifdef OSL_SUPPORT
 #include <osl/macros.h>
@@ -510,15 +514,18 @@
 	else
 		constraint = isl_inequality_alloc(ls);
 
-	for (j = 0; j < nvariables; ++j)
-		isl_constraint_set_coefficient(constraint, isl_dim_out, j,
-					       row[1 + j]);
+	for (j = 0; j < nvariables; ++j) {
+		isl_val *val = cloog_int_to_isl_val(isl_constraint_get_ctx(constraint), row[1 + j]);
+		isl_constraint_set_coefficient_val(constraint, isl_dim_out, j, val);
+	}
 
-	for (j = 0; j < nparam; ++j)
-		isl_constraint_set_coefficient(constraint, isl_dim_param, j,
-					       row[1 + nvariables + j]);
+	for (j = 0; j < nparam; ++j) {
+		isl_val *val = cloog_int_to_isl_val(isl_constraint_get_ctx(constraint), row[1 + nvariables + j]);
+		isl_constraint_set_coefficient_val(constraint, isl_dim_param, j, val);
+	}
 
-	isl_constraint_set_constant(constraint, row[1 + nvariables + nparam]);
+	isl_val *val = cloog_int_to_isl_val(isl_constraint_get_ctx(constraint), row[1 + nvariables + nparam]);
+	isl_constraint_set_constant_val(constraint, val);
 
 	return constraint;
 }
@@ -631,7 +638,6 @@
   return domain;
 }
 
-
 /**
  * Converts an openscop scattering relation to a CLooG scattering.
  * \param[in,out] state    CLooG state.
@@ -779,10 +785,22 @@
 void cloog_domain_stride(CloogDomain *domain, int strided_level,
 	cloog_int_t *stride, cloog_int_t *offset)
 {
+	int ret = -1;
 	isl_set *set = isl_set_from_cloog_domain(domain);
-	isl_set_dim_residue_class(set, strided_level - 1, stride, offset);
-	if (!isl_int_is_zero(*offset))
-		isl_int_sub(*offset, *stride, *offset);
+	isl_val *stride_val = NULL;
+	isl_val *offset_val = NULL;
+	ret = isl_set_dim_residue_class_val(set, strided_level - 1, &stride_val, &offset_val);
+	if (ret != 0)
+		cloog_die("failure to compute stride.\n");
+	isl_val_to_cloog_int(stride_val, stride);
+	isl_val_to_cloog_int(offset_val, offset);
+
+	if (!cloog_int_is_zero(*offset))
+		cloog_int_sub(*offset, *stride, *offset);
+
+	isl_val_free(stride_val);
+	isl_val_free(offset_val);
+
 	return;
 }
 
@@ -796,7 +814,7 @@
 {
 	struct cloog_can_stride *ccs = (struct cloog_can_stride *)user;
 	int i;
-	isl_int v;
+	isl_val *v;
 	unsigned n_div;
 
 	if (isl_constraint_is_equality(c)) {
@@ -804,21 +822,22 @@
 		return 0;
 	}
 
-	isl_int_init(v);
-	isl_constraint_get_coefficient(c, isl_dim_set, ccs->level - 1, &v);
-	if (isl_int_is_pos(v)) {
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, ccs->level - 1);
+	if (isl_val_is_pos(v)) {
 		n_div = isl_constraint_dim(c, isl_dim_div);
+
 		for (i = 0; i < n_div; ++i) {
-			isl_constraint_get_coefficient(c, isl_dim_div, i, &v);
-			if (!isl_int_is_zero(v))
+			isl_val_free(v);
+			v = isl_constraint_get_coefficient_val(c, isl_dim_div, i);
+			if (!isl_val_is_zero(v))
 				break;
 		}
 		if (i < n_div)
 			ccs->can_stride = 0;
 	}
-	isl_int_clear(v);
-	isl_constraint_free(c);
+	isl_val_free(v);
 
+	isl_constraint_free(c);
 	return 0;
 }
 
@@ -903,7 +922,7 @@
 static int constraint_stride_lower(__isl_take isl_constraint *c, void *user)
 {
 	struct cloog_stride_lower *csl = (struct cloog_stride_lower *)user;
-	isl_int v;
+	isl_val *v;
 	isl_constraint *bound;
 	isl_aff *b;
 
@@ -912,31 +931,31 @@
 		return 0;
 	}
 
-	isl_int_init(v);
-	isl_constraint_get_coefficient(c, isl_dim_set, csl->level - 1, &v);
-	if (!isl_int_is_pos(v)) {
-		isl_int_clear(v);
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, csl->level - 1);
+	if (!isl_val_is_pos(v)) {
+		isl_val_free(v);
 		isl_constraint_free(c);
 
 		return 0;
 	}
+	isl_val_free(v);
 
 	b = isl_constraint_get_bound(c, isl_dim_set, csl->level - 1);
 
 	b = isl_aff_neg(b);
-	b = isl_aff_add_constant(b, csl->stride->offset);
-	b = isl_aff_scale_down(b, csl->stride->stride);
+	b = isl_aff_add_constant_val(b, cloog_int_to_isl_val(isl_constraint_get_ctx(c), csl->stride->offset));
+	b = isl_aff_scale_down_val(b, cloog_int_to_isl_val(isl_constraint_get_ctx(c), csl->stride->stride));
 	b = isl_aff_floor(b);
-	b = isl_aff_scale(b, csl->stride->stride);
-	isl_int_neg(v, csl->stride->offset);
-	b = isl_aff_add_constant(b, v);
+	b = isl_aff_scale_val(b, cloog_int_to_isl_val(isl_constraint_get_ctx(c), csl->stride->stride));
+	v = cloog_int_to_isl_val(isl_constraint_get_ctx(c), csl->stride->offset);
+	v = isl_val_neg(v);
+	b = isl_aff_add_constant_val(b, v);
 	b = isl_aff_add_coefficient_si(b, isl_dim_in, csl->level - 1, 1);
 
 	bound = isl_inequality_from_aff(b);
 
 	csl->bounds = isl_basic_set_add_constraint(csl->bounds, bound);
 
-	isl_int_clear(v);
 	isl_constraint_free(c);
 
 	return 0;
@@ -960,7 +979,7 @@
 static int constraint_stride_lower_c(__isl_take isl_constraint *c, void *user)
 {
 	struct cloog_stride_lower *csl = (struct cloog_stride_lower *)user;
-	isl_int v;
+	isl_val *v;
 	isl_constraint *bound;
 	isl_constraint *csl_c;
 	isl_aff *d, *b;
@@ -970,10 +989,9 @@
 		return 0;
 	}
 
-	isl_int_init(v);
-	isl_constraint_get_coefficient(c, isl_dim_set, csl->level - 1, &v);
-	if (!isl_int_is_pos(v)) {
-		isl_int_clear(v);
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, csl->level - 1);
+	if (!isl_val_is_pos(v)) {
+		isl_val_free(v);
 		isl_constraint_free(c);
 
 		return 0;
@@ -984,15 +1002,15 @@
 	d = isl_constraint_get_aff(csl_c);
 	d = isl_aff_drop_dims(d, isl_dim_div, 0, isl_aff_dim(d, isl_dim_div));
 	d = isl_aff_set_coefficient_si(d, isl_dim_in, csl->level - 1, 0);
-	d = isl_aff_scale(d, csl->stride->factor);
+	d = isl_aff_scale_val(d, cloog_int_to_isl_val(isl_constraint_get_ctx(csl_c), csl->stride->factor));
 
 	b = isl_constraint_get_bound(c, isl_dim_set, csl->level - 1);
 
 	b = isl_aff_neg(b);
 	b = isl_aff_add(b, isl_aff_copy(d));
-	b = isl_aff_scale_down(b, csl->stride->stride);
+	b = isl_aff_scale_down_val(b, cloog_int_to_isl_val(isl_constraint_get_ctx(csl_c), csl->stride->stride));
 	b = isl_aff_floor(b);
-	b = isl_aff_scale(b, csl->stride->stride);
+	b = isl_aff_scale_val(b, cloog_int_to_isl_val(isl_constraint_get_ctx(csl_c), csl->stride->stride));
 	b = isl_aff_sub(b, d);
 	b = isl_aff_add_coefficient_si(b, isl_dim_in, csl->level - 1, 1);
 
@@ -1000,7 +1018,7 @@
 
 	csl->bounds = isl_basic_set_add_constraint(csl->bounds, bound);
 
-	isl_int_clear(v);
+	isl_val_free(v);
 	isl_constraint_free(c);
 
 	return 0;
@@ -1090,28 +1108,30 @@
 static int constraint_bound_split(__isl_take isl_constraint *c, void *user)
 {
 	struct cloog_bound_split *cbs = (struct cloog_bound_split *)user;
-	isl_int v;
+	isl_val *v;
 	int i;
 	int handle = 0;
 
-	isl_int_init(v);
-	isl_constraint_get_coefficient(c, isl_dim_set, cbs->level - 1, &v);
-	if (!cbs->lower && isl_int_is_pos(v))
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, cbs->level - 1);
+	if (!cbs->lower && isl_val_is_pos(v))
 		cbs->lower = handle = 1;
-	else if (!cbs->upper && isl_int_is_neg(v))
+	else if (!cbs->upper && isl_val_is_neg(v))
 		cbs->upper = handle = 1;
+
 	if (handle) {
 		for (i = 0; i < isl_set_dim(cbs->set, isl_dim_param); ++i) {
-			isl_constraint_get_coefficient(c, isl_dim_param, i, &v);
-			if (isl_int_is_zero(v))
+			isl_val_free(v);
+			v = isl_constraint_get_coefficient_val(c, isl_dim_param, i);
+			if (isl_val_is_zero(v))
 				continue;
+
 			cbs->set = isl_set_split_dims(cbs->set,
 							isl_dim_param, i, 1);
 		}
 	}
-	isl_int_clear(v);
-	isl_constraint_free(c);
+	isl_val_free(v);
 
+	isl_constraint_free(c);
 	return (cbs->lower && cbs->upper) ? -1 : 0;
 }
 
@@ -1203,7 +1223,7 @@
  * - scattdims is the total number of scattering dimentions.
  */
 int cloog_scattering_lazy_block(CloogScattering *s1, CloogScattering *s2,
-			    CloogScatteringList *scattering, int scattdims)
+			CloogScatteringList *scattering, int scattdims)
 {
 	int i;
 	struct isl_space *dim;
@@ -1211,8 +1231,8 @@
 	struct isl_set *delta;
 	isl_map *map1 = isl_map_from_cloog_scattering(s1);
 	isl_map *map2 = isl_map_from_cloog_scattering(s2);
-	int fixed, block;
-	isl_int cst;
+	int block;
+	isl_val *cst;
 	unsigned n_scat;
 
 	n_scat = isl_map_dim(map1, isl_dim_out);
@@ -1225,22 +1245,33 @@
 	rel = isl_map_apply_domain(rel, isl_map_copy(map1));
 	rel = isl_map_apply_range(rel, isl_map_copy(map2));
 	delta = isl_map_deltas(rel);
-	isl_int_init(cst);
+	cst = NULL;
 	for (i = 0; i < n_scat; ++i) {
-		fixed = isl_set_fast_dim_is_fixed(delta, i, &cst);
-		if (fixed != 1)
+		cst = isl_set_plain_get_val_if_fixed(delta, isl_dim_set, i);
+		if (!cst){
+			isl_val_free(cst);
 			break;
-		if (isl_int_is_zero(cst))
+		}
+		if (isl_val_is_zero(cst)){
+			isl_val_free(cst);
 			continue;
-		if (i + 1 < n_scat)
+		}
+		if (i + 1 < n_scat){
+			isl_val_free(cst);
 			break;
-		if (!isl_int_is_one(cst))
+		}
+		if (!isl_val_is_one(cst)){
+			isl_val_free(cst);
 			break;
-		if (!injective_scattering(scattering))
+		}
+		if (!injective_scattering(scattering)){
+			isl_val_free(cst);
 			break;
+		}
+
+		isl_val_free(cst);
 	}
 	block = i >= n_scat;
-	isl_int_clear(cst);
 	isl_set_free(delta);
 	return block;
 }
@@ -1345,10 +1376,25 @@
  * If value is not NULL, then it is set to the constant value of dimension.
  */
 int cloog_scattering_lazy_isscalar(CloogScattering *scatt, int dimension,
-					cloog_int_t *value)
+	cloog_int_t *value)
 {
 	isl_map *map = isl_map_from_cloog_scattering(scatt);
-	return isl_map_fast_is_fixed(map, isl_dim_out, dimension, value);
+	isl_val *v = isl_map_plain_get_val_if_fixed(map, isl_dim_out, dimension);
+	if (v != NULL) {
+		if (!isl_val_is_nan(v)){
+			if (value != NULL)
+				isl_val_to_cloog_int(v, value);
+
+			isl_val_free(v);
+			return 1;
+		}
+		else {
+			isl_val_free(v);
+			return 0;
+		}
+	}
+
+	return 0;
 }
 
 
@@ -1362,7 +1408,22 @@
 	cloog_int_t *value)
 {
 	isl_set *set = isl_set_from_cloog_domain(domain);
-	return isl_set_fast_dim_is_fixed(set, dimension, value);
+	isl_val *cst = isl_set_plain_get_val_if_fixed(set, isl_dim_set, dimension);
+	if (cst != NULL) {
+		if (!isl_val_is_nan(cst)){
+			if (value != NULL)
+				isl_val_to_cloog_int(cst, value);
+
+			isl_val_free(cst);
+			return 1;
+		}
+		else {
+			isl_val_free(cst);
+			return 0;
+		}
+	}
+
+	return 0;
 }
 
 
@@ -1595,7 +1656,7 @@
 		cloog_int_mul(tmp, tmp, d);
 		cloog_int_sub(c, c, tmp);
 		cloog_int_swap(c, d);
-	    cloog_int_swap(e, f);
+		cloog_int_swap(e, f);
 	}
 	cloog_int_set(*g, c);
 	if (cloog_int_is_zero(a))
@@ -1631,49 +1692,70 @@
 static CloogStride *construct_stride(isl_constraint *c, int level)
 {
 	int i, n, sign;
-	isl_int v, m, gcd, stride, factor;
+	isl_val *v, *m, *gcd, *stride;
+	isl_val *v_copy, *m_copy, *gcd_copy;
+	cloog_int_t c_v, c_m, c_gcd, c_stride, c_factor;
 	CloogStride *s;
+	isl_ctx *ctx = isl_constraint_get_ctx(c);;
 
 	if (!c)
 		return NULL;
 
-	isl_int_init(v);
-	isl_int_init(m);
-	isl_int_init(gcd);
-	isl_int_init(factor);
-	isl_int_init(stride);
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, level - 1);
 
-	isl_constraint_get_coefficient(c, isl_dim_set, level - 1, &v);
-	sign = isl_int_sgn(v);
-	isl_int_abs(m, v);
+	sign = isl_val_sgn(v);
+	m = isl_val_abs(v); /* *takes* v. */
 
-	isl_int_set_si(gcd, 0);
+	gcd = isl_val_int_from_si(ctx, 0);
 	n = isl_constraint_dim(c, isl_dim_div);
 	for (i = 0; i < n; ++i) {
-		isl_constraint_get_coefficient(c, isl_dim_div, i, &v);
-		isl_int_gcd(gcd, gcd, v);
+		v = isl_constraint_get_coefficient_val(c, isl_dim_div, i);
+		gcd = isl_val_gcd(gcd, v);
 	}
 
-	isl_int_gcd(v, m, gcd);
-	isl_int_divexact(stride, gcd, v);
+	m_copy = isl_val_copy(m);
+	gcd_copy = isl_val_copy(gcd);
 
-	if (isl_int_is_zero(stride) || isl_int_is_one(stride))
+	v = isl_val_gcd(m, gcd);
+
+	v_copy = isl_val_copy(v);
+	gcd = isl_val_copy(gcd_copy);
+	stride = isl_val_div(gcd, v);
+
+	if (isl_val_is_zero(stride) || isl_val_is_one(stride))
 		s = NULL;
 	else {
-		Euclid(m, stride, &factor, &v, &gcd);
+		cloog_int_init(c_m);
+		cloog_int_init(c_stride);
+		cloog_int_init(c_v);
+		cloog_int_init(c_gcd);
+		cloog_int_init(c_factor);
+
+		isl_val_to_cloog_int(m_copy, &c_m);
+		isl_val_to_cloog_int(stride, &c_stride);
+		isl_val_to_cloog_int(v_copy, &c_v);
+		isl_val_to_cloog_int(gcd_copy, &c_gcd);
+
+		Euclid(c_m, c_stride, &c_factor, &c_v, &c_gcd);
 		if (sign > 0)
-			isl_int_neg(factor, factor);
+			cloog_int_neg(c_factor, c_factor);
 
 		c = isl_constraint_copy(c);
-		s = cloog_stride_alloc_from_constraint(stride,
-			    cloog_constraint_from_isl_constraint(c), factor);
+		s = cloog_stride_alloc_from_constraint(c_stride,
+					cloog_constraint_from_isl_constraint(c), c_factor);
+
+
+		cloog_int_clear(c_m);
+		cloog_int_clear(c_stride);
+		cloog_int_clear(c_v);
+		cloog_int_clear(c_gcd);
+		cloog_int_clear(c_factor);
 	}
 
-	isl_int_clear(stride);
-	isl_int_clear(factor);
-	isl_int_clear(gcd);
-	isl_int_clear(m);
-	isl_int_clear(v);
+	isl_val_free(stride);
+	isl_val_free(gcd_copy);
+	isl_val_free(m_copy);
+	isl_val_free(v_copy);
 
 	return s;
 }
@@ -1694,7 +1776,7 @@
 {
 	struct cloog_isl_find_stride_data *data;
 	int n;
-	isl_int v;
+	isl_val *v;
 
 	if (!isl_constraint_is_equality(c)) {
 		isl_constraint_free(c);
@@ -1714,13 +1796,11 @@
 		return 0;
 	}
 
-	isl_int_init(v);
-
-	isl_constraint_get_coefficient(c, isl_dim_set, data->level - 1, &v);
-	if (!isl_int_is_zero(v))
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, data->level - 1);
+	if (!isl_val_is_zero(v))
 		data->stride = construct_stride(c, data->level);
 
-	isl_int_clear(v);
+	isl_val_free(v);
 
 	isl_constraint_free(c);
 
@@ -1769,7 +1849,7 @@
 	int level;
 	isl_constraint *c;
 	isl_set *set;
-	isl_int *n;
+	isl_val *n;
 };
 
 
@@ -1782,11 +1862,11 @@
  * with l the given lower bound and i the iterator identified by level.
  */
 static int is_valid_unrolling_lower_bound(struct cloog_can_unroll *ccu,
-	__isl_keep isl_constraint *c, isl_int *v)
+	__isl_keep isl_constraint *c, isl_val **v)
 {
 	unsigned n_div;
 	isl_aff *aff;
-	enum isl_lp_result res;
+	enum isl_lp_result;
 
 	n_div = isl_constraint_dim(c, isl_dim_div);
 	if (isl_constraint_involves_dims(c, isl_dim_div, 0, n_div))
@@ -1796,15 +1876,19 @@
 	aff = isl_aff_ceil(aff);
 	aff = isl_aff_neg(aff);
 	aff = isl_aff_add_coefficient_si(aff, isl_dim_in, ccu->level - 1, 1);
-	res = isl_set_max(ccu->set, aff, v);
+	*v = isl_set_max_val(ccu->set, aff);
 	isl_aff_free(aff);
 
-	if (res == isl_lp_unbounded)
-		return 0;
+	if (!*v || isl_val_is_nan(*v))
+		cloog_die("Fail to decide about unrolling (cannot find max)");
 
-	assert(res == isl_lp_ok);
+	if (isl_val_is_infty(*v) || isl_val_is_neginfty(*v)){
+		isl_val_free(*v);
+		*v = NULL;
+		return 0;
+	}
 
-	cloog_int_add_ui(*v, *v, 1);
+	*v = isl_val_add_ui(*v, 1);
 
 	return 1;
 }
@@ -1818,21 +1902,21 @@
 static int constraint_can_unroll(__isl_take isl_constraint *c, void *user)
 {
 	struct cloog_can_unroll *ccu = (struct cloog_can_unroll *)user;
-	isl_int v;
-	isl_int count;
+	isl_val *v;
+	isl_val *count = NULL;
 
-	isl_int_init(v);
-	isl_int_init(count);
-	isl_constraint_get_coefficient(c, isl_dim_set, ccu->level - 1, &v);
-	if (isl_int_is_pos(v) &&
-	    is_valid_unrolling_lower_bound(ccu, c, &count) &&
-	    (!ccu->c || isl_int_lt(count, *ccu->n))) {
+	v = isl_constraint_get_coefficient_val(c, isl_dim_set, ccu->level - 1);
+	if (isl_val_is_pos(v) &&
+			is_valid_unrolling_lower_bound(ccu, c, &count) &&
+			(!ccu->c || (isl_val_lt(count, ccu->n))) ) {
 		isl_constraint_free(ccu->c);
 		ccu->c = isl_constraint_copy(c);
-		isl_int_set(*ccu->n, count);
+		if (ccu->n)
+			isl_val_free(ccu->n);
+		ccu->n = isl_val_copy(count);
 	}
-	isl_int_clear(count);
-	isl_int_clear(v);
+	isl_val_free(count);
+	isl_val_free(v);
 	isl_constraint_free(c);
 
 	return 0;
@@ -1872,7 +1956,8 @@
 	CloogConstraint **lb)
 {
 	isl_set *set = isl_set_from_cloog_domain(domain);
-	struct cloog_can_unroll ccu = { 1, level, NULL, set, n };
+	isl_val *v = cloog_int_to_isl_val(isl_set_get_ctx(set), *n);
+	struct cloog_can_unroll ccu = { 1, level, NULL, set, v };
 	int r;
 
 	*lb = NULL;
@@ -1887,6 +1972,11 @@
 
 	*lb = cloog_constraint_from_isl_constraint(ccu.c);
 
+	isl_val_to_cloog_int(ccu.n, n);
+	/* Note: we have to free ccu.n and not v because v has been
+	 * freed and replaced in ccu during isl_set_foreach_basic_set
+	 */
+	isl_val_free(ccu.n);
 	return ccu.can_unroll;
 }
 
@@ -1904,6 +1994,7 @@
 {
 	isl_aff *aff;
 	isl_set *set = isl_set_from_cloog_domain(domain);
+	isl_ctx *ctx = isl_set_get_ctx(set);
 	isl_constraint *c;
 	isl_constraint *eq;
 
@@ -1911,7 +2002,7 @@
 	aff = isl_constraint_get_bound(c, isl_dim_set, level - 1);
 	aff = isl_aff_ceil(aff);
 	aff = isl_aff_add_coefficient_si(aff, isl_dim_in, level - 1, -1);
-	aff = isl_aff_add_constant(aff, offset);
+	aff = isl_aff_add_constant_val(aff, cloog_int_to_isl_val(ctx, offset));
 	eq = isl_equality_from_aff(aff);
 	set = isl_set_add_constraint(set, eq);
 
