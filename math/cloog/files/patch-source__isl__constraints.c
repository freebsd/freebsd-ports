--- ./source/isl/constraints.c.orig	2013-10-11 04:27:03.000000000 -0300
+++ ./source/isl/constraints.c	2014-07-07 20:50:52.000000000 -0300
@@ -5,11 +5,51 @@
 #include <cloog/isl/backend.h>
 #include <isl/aff.h>
 #include <isl/set.h>
+#include <isl/val.h>
+#include <isl/val_gmp.h>
 
 
 #define ALLOC(type) (type*)malloc(sizeof(type))
 #define ALLOCN(type,n) (type*)malloc((n)*sizeof(type))
 
+__isl_give isl_val *cloog_int_to_isl_val(isl_ctx* ctx, cloog_int_t c)
+{
+	isl_val *v;
+#if defined(CLOOG_INT_INT)
+	v = isl_val_int_from_si(ctx, c);
+#elif defined(CLOOG_INT_LONG)
+	v = isl_val_int_from_si(ctx, c);
+#elif defined(CLOOG_INT_LONG_LONG)
+	v = isl_val_int_from_si(ctx, c);
+#elif defined(CLOOG_INT_GMP)
+	v = isl_val_int_from_gmp(ctx, c);
+#else
+#error "No integer type defined"
+#endif
+	return v;
+}
+
+/*
+ * CLooG'll be dealing in integers so we expect numerator/1 form
+ * from isl_val. Thus get numerator to assign to cloog_int
+ */
+void isl_val_to_cloog_int(__isl_keep isl_val *val, cloog_int_t *cint)
+{
+	assert(isl_val_is_int(val));
+#if defined(CLOOG_INT_INT)
+	*cint = isl_val_get_num_si(val);
+#elif defined(CLOOG_INT_LONG)
+	*cint = isl_val_get_num_si(val);
+#elif defined(CLOOG_INT_LONG_LONG)
+	*cint = isl_val_get_num_si(val);
+#elif defined(CLOOG_INT_GMP)
+	isl_val_get_num_gmp(val, *cint);
+#else
+#error "No integer type defined"
+#endif
+}
+
+
 CloogConstraintSet *cloog_constraint_set_from_isl_basic_set(struct isl_basic_set *bset)
 {
 	return (CloogConstraintSet *)bset;
@@ -266,53 +306,65 @@
 static int cloog_constraint_equal_type(CloogConstraint *cc, int level)
 { 
 	int i;
-	isl_int c;
+	isl_val *c;
 	int type = EQTYPE_NONE;
 	struct isl_constraint *constraint = cloog_constraint_to_isl(cc);
     
-	isl_int_init(c);
-	isl_constraint_get_constant(constraint, &c);
-	if (!isl_int_is_zero(c))
+	c = isl_constraint_get_constant_val(constraint);
+	if (!isl_val_is_zero(c))
 		type = EQTYPE_CONSTANT;
-	isl_constraint_get_coefficient(constraint, isl_dim_set, level - 1, &c);
-	if (!isl_int_is_one(c) && !isl_int_is_negone(c))
+	isl_val_free(c);
+	c = isl_constraint_get_coefficient_val(constraint, isl_dim_set, level - 1);
+	if (!isl_val_is_one(c) && !isl_val_is_negone(c))
 		type = EQTYPE_EXAFFINE;
+	isl_val_free(c);
 	for (i = 0; i < isl_constraint_dim(constraint, isl_dim_param); ++i) {
-		isl_constraint_get_coefficient(constraint, isl_dim_param, i, &c);
-		if (isl_int_is_zero(c))
+		c = isl_constraint_get_coefficient_val(constraint, isl_dim_param, i);
+		if (isl_val_is_zero(c)){
+			isl_val_free(c);
 			continue;
-		if ((!isl_int_is_one(c) && !isl_int_is_negone(c)) ||
+		}
+		if ((!isl_val_is_one(c) && !isl_val_is_negone(c)) ||
 		    type != EQTYPE_NONE) {
 			type = EQTYPE_EXAFFINE;
+			isl_val_free(c);
 			break;
 		}
 		type = EQTYPE_PUREITEM;
+		isl_val_free(c);
 	}
 	for (i = 0; i < isl_constraint_dim(constraint, isl_dim_set); ++i) {
 		if (i == level - 1)
 			continue;
-		isl_constraint_get_coefficient(constraint, isl_dim_set, i, &c);
-		if (isl_int_is_zero(c))
+		c = isl_constraint_get_coefficient_val(constraint, isl_dim_set, i);
+		if (isl_val_is_zero(c)){
+			isl_val_free(c);
 			continue;
-		if ((!isl_int_is_one(c) && !isl_int_is_negone(c)) ||
+		}
+		if ((!isl_val_is_one(c) && !isl_val_is_negone(c)) ||
 		    type != EQTYPE_NONE) {
 			type = EQTYPE_EXAFFINE;
+			isl_val_free(c);
 			break;
 		}
 		type = EQTYPE_PUREITEM;
+		isl_val_free(c);
 	}
 	for (i = 0; i < isl_constraint_dim(constraint, isl_dim_div); ++i) {
-		isl_constraint_get_coefficient(constraint, isl_dim_div, i, &c);
-		if (isl_int_is_zero(c))
+		c = isl_constraint_get_coefficient_val(constraint, isl_dim_div, i);
+		if (isl_val_is_zero(c)){
+			isl_val_free(c);
 			continue;
-		if ((!isl_int_is_one(c) && !isl_int_is_negone(c)) ||
+		}
+		if ((!isl_val_is_one(c) && !isl_val_is_negone(c)) ||
 		    type != EQTYPE_NONE) {
 			type = EQTYPE_EXAFFINE;
+			isl_val_free(c);
 			break;
 		}
 		type = EQTYPE_PUREITEM;
+		isl_val_free(c);
 	}
-	isl_int_clear(c);
 
 	if (type == EQTYPE_NONE)
 		type = EQTYPE_CONSTANT;
@@ -447,27 +499,31 @@
 {
 	int i, nb_elts;
 	unsigned dim = cloog_constraint_total_dimension(constraint);
-	cloog_int_t c;
+	isl_val *c;
 	struct clast_reduction *r;
 	struct clast_expr *e = NULL;
 	isl_aff *div;
+	cloog_int_t cint;
 
+	cloog_int_init(cint);
 	div = isl_constraint_get_div(cloog_constraint_to_isl(constraint), pos);
 
-	cloog_int_init(c);
 	for (i = 0, nb_elts = 0; i < dim; ++i) {
 		struct cloog_isl_dim dim;
 
 		dim = constraint_cloog_dim_to_isl_dim(constraint, i);
 		if (dim.type == isl_dim_set)
 			dim.type = isl_dim_in;
-		isl_aff_get_coefficient(div, dim.type, dim.pos, &c);
-		if (!cloog_int_is_zero(c))
+		c = isl_aff_get_coefficient_val(div, dim.type, dim.pos);
+		if (!isl_val_is_zero(c))
 			++nb_elts;
+
+		isl_val_free(c);
 	}
-	isl_aff_get_constant(div, &c);
-	if (!cloog_int_is_zero(c))
+	c = isl_aff_get_constant_val(div);
+	if (!isl_val_is_zero(c))
 		++nb_elts;
+	isl_val_free(c);
 
 	r = new_clast_reduction(clast_red_sum, nb_elts);
 	for (i = 0, nb_elts = 0; i < dim; ++i) {
@@ -477,22 +533,35 @@
 		dim = constraint_cloog_dim_to_isl_dim(constraint, i);
 		if (dim.type == isl_dim_set)
 			dim.type = isl_dim_in;
-		isl_aff_get_coefficient(div, dim.type, dim.pos, &c);
-		if (cloog_int_is_zero(c))
+		c = isl_aff_get_coefficient_val(div, dim.type, dim.pos);
+		if (isl_val_is_zero(c)){
+			isl_val_free(c);
 			continue;
+		}
 
 		v = cloog_constraint_variable_expr(constraint, 1 + i, names);
 
-		r->elts[nb_elts++] = &new_clast_term(c, v)->expr;
+		/* We are interested only in the numerator */
+		cloog_int_set_si(cint, isl_val_get_num_si(c));
+		r->elts[nb_elts++] = &new_clast_term(cint, v)->expr;
+
+		isl_val_free(c);
 	}
-	isl_aff_get_constant(div, &c);
-	if (!cloog_int_is_zero(c))
-		r->elts[nb_elts++] = &new_clast_term(c, NULL)->expr;
 
-	isl_aff_get_denominator(div, &c);
-	e = &new_clast_binary(clast_bin_fdiv, &r->expr, c)->expr;
+	c = isl_aff_get_constant_val(div);
+	if (!isl_val_is_zero(c)) {
+		/* We are interested only in the numerator */
+		cloog_int_set_si(cint, isl_val_get_num_si(c));
+		r->elts[nb_elts++] = &new_clast_term(cint, NULL)->expr;
+	}
+	isl_val_free(c);
 
-	cloog_int_clear(c);
+	c = isl_aff_get_denominator_val(div);
+	isl_val_to_cloog_int(c, &cint);
+	isl_val_free(c);
+	e = &new_clast_binary(clast_bin_fdiv, &r->expr, cint)->expr;
+
+	cloog_int_clear(cint);
 
 	isl_aff_free(div);
 
@@ -529,37 +598,34 @@
  */
 int cloog_constraint_involves(CloogConstraint *constraint, int v)
 {
-	isl_int c;
+	isl_val *c;
 	int res;
 
-	isl_int_init(c);
-	cloog_constraint_coefficient_get(constraint, v, &c);
-	res = !isl_int_is_zero(c);
-	isl_int_clear(c);
+	c = cloog_constraint_coefficient_get_val(constraint, v);
+	res = !isl_val_is_zero(c);
+	isl_val_free(c);
 	return res;
 }
 
 int cloog_constraint_is_lower_bound(CloogConstraint *constraint, int v)
 {
-	isl_int c;
+	isl_val *c;
 	int res;
 
-	isl_int_init(c);
-	cloog_constraint_coefficient_get(constraint, v, &c);
-	res = isl_int_is_pos(c);
-	isl_int_clear(c);
+	c = cloog_constraint_coefficient_get_val(constraint, v);
+	res = isl_val_is_pos(c);
+	isl_val_free(c);
 	return res;
 }
 
 int cloog_constraint_is_upper_bound(CloogConstraint *constraint, int v)
 {
-	isl_int c;
+	isl_val *c;
 	int res;
 
-	isl_int_init(c);
-	cloog_constraint_coefficient_get(constraint, v, &c);
-	res = isl_int_is_neg(c);
-	isl_int_clear(c);
+	c = cloog_constraint_coefficient_get_val(constraint, v);
+	res = isl_val_is_neg(c);
+	isl_val_free(c);
 	return res;
 }
 
@@ -585,15 +651,37 @@
 {
 	struct cloog_isl_dim dim;
 	isl_constraint *c;
+	isl_val *ival;
 
 	if (!constraint)
-		return;
+		val = NULL;
 
 	dim = constraint_cloog_dim_to_isl_dim(constraint, var);
 	c = cloog_constraint_to_isl(constraint);
-	isl_constraint_get_coefficient(c, dim.type, dim.pos, val);
+	ival = isl_constraint_get_coefficient_val(c, dim.type, dim.pos);
+
+	isl_val_to_cloog_int(ival, val);
+	isl_val_free(ival);
 }
 
+isl_val *cloog_constraint_coefficient_get_val(CloogConstraint *constraint,
+			int var)
+{
+	struct cloog_isl_dim dim;
+	isl_constraint *c;
+	isl_val *val;
+
+	if (!constraint)
+		return NULL;
+
+	dim = constraint_cloog_dim_to_isl_dim(constraint, var);
+	c = cloog_constraint_to_isl(constraint);
+	val = isl_constraint_get_coefficient_val(c, dim.type, dim.pos);
+	return val;
+}
+
+
+
 void cloog_constraint_coefficient_set(CloogConstraint *constraint,
 			int var, cloog_int_t val)
 {
@@ -604,14 +692,26 @@
 
 	dim = constraint_cloog_dim_to_isl_dim(constraint, var);
 	c = cloog_constraint_to_isl(constraint);
-	isl_constraint_set_coefficient(c, dim.type, dim.pos, val);
+	isl_constraint_set_coefficient_val(c, dim.type, dim.pos,
+	        cloog_int_to_isl_val(isl_constraint_get_ctx(c), val));
 }
 
 void cloog_constraint_constant_get(CloogConstraint *constraint, cloog_int_t *val)
 {
-	isl_constraint_get_constant(cloog_constraint_to_isl(constraint), val);
+	isl_val *ival;
+	ival = isl_constraint_get_constant_val(cloog_constraint_to_isl(constraint));
+	isl_val_to_cloog_int(ival, val);
+	isl_val_free(ival);
+}
+
+
+__isl_give isl_val *cloog_constraint_constant_get_val(CloogConstraint *constraint)
+{
+	return isl_constraint_get_constant_val(cloog_constraint_to_isl(constraint));
 }
 
+
+
 /**
  * Copy the coefficient of constraint c into dst in PolyLib order,
  * i.e., first the coefficients of the variables, then the coefficients
@@ -700,15 +800,11 @@
 
 static int add_constant_term(CloogConstraint *c, void *user)
 {
-	isl_int *bound = (isl_int *)user;
-	isl_int v;
-
-	isl_int_init(v);
-
-	cloog_constraint_constant_get(c, &v);
-	isl_int_add(*bound, *bound, v);
+	isl_val **bound = (isl_val **)user;
+	isl_val *v;
 
-	isl_int_clear(v);
+	v = cloog_constraint_constant_get_val(c);
+	*bound = isl_val_add(*bound, v);
 
 	return 0;
 }
@@ -822,11 +918,14 @@
 	c = isl_constraint_set_coefficient_si(c, isl_dim_set, dim.pos, -1);
 	bset = isl_basic_set_add_constraint(bset, c);
 
-	isl_int_set_si(*bound, 0);
+	cloog_int_set_si(*bound, 0);
+	isl_val *v = cloog_int_to_isl_val(isl_basic_set_get_ctx(bset), *bound);
 	constraints = cloog_constraint_set_from_isl_basic_set(bset);
 	cloog_constraint_set_foreach_constraint(constraints,
-						add_constant_term, bound);
+	                add_constant_term, &v);
+	isl_val_to_cloog_int(v, bound); //return the value to bound
 
+	isl_val_free(v);
 	isl_basic_set_free(orig);
 	return cloog_constraint_set_from_isl_basic_set(bset);
 }
@@ -896,31 +995,27 @@
 	isl_space *dim = isl_constraint_get_space(c);
 	isl_local_space *ls = isl_local_space_from_space(dim);
 	isl_aff *offset = isl_aff_zero_on_domain(ls);
-	isl_int u;
+	isl_val *u;
 	unsigned nparam, nvar;
 
-	isl_int_init(u);
-
 	nparam = isl_constraint_dim(c, isl_dim_param);
 	nvar = isl_constraint_dim(c, isl_dim_set);
 
 	for (i = 0; i < nparam; ++i) {
-		isl_constraint_get_coefficient(c, isl_dim_param, i, &u);
-		isl_int_mul(u, u, stride->factor);
-		offset = isl_aff_set_coefficient(offset, isl_dim_param, i, u);
+		u = isl_constraint_get_coefficient_val(c, isl_dim_param, i);
+		u = isl_val_mul(u, cloog_int_to_isl_val(isl_constraint_get_ctx(c), stride->factor));
+		offset = isl_aff_set_coefficient_val(offset, isl_dim_param, i, u);
 	}
 	for (i = 0; i < nvar; ++i) {
 		if (i == level - 1)
 			continue;
-		isl_constraint_get_coefficient(c, isl_dim_set, i, &u);
-		isl_int_mul(u, u, stride->factor);
-		offset = isl_aff_set_coefficient(offset, isl_dim_in, i, u);
+		u = isl_constraint_get_coefficient_val(c, isl_dim_set, i);
+		u = isl_val_mul(u, cloog_int_to_isl_val(isl_constraint_get_ctx(c), stride->factor));
+		offset = isl_aff_set_coefficient_val(offset, isl_dim_in, i, u);
 	}
-	isl_constraint_get_constant(c, &u);
-	isl_int_mul(u, u, stride->factor);
-	offset = isl_aff_set_constant(offset, u);
-
-	isl_int_clear(u);
+	u = isl_constraint_get_constant_val(c);
+	u = isl_val_mul(u, cloog_int_to_isl_val(isl_constraint_get_ctx(c), stride->factor));
+	offset = isl_aff_set_constant_val(offset, u);
 
 	return offset;
 }
@@ -953,9 +1048,9 @@
 	offset = extract_stride_offset(stride_c, level, stride);
 
 	lower = isl_aff_sub(lower, isl_aff_copy(offset));
-	lower = isl_aff_scale_down(lower, stride->stride);
+	lower = isl_aff_scale_down_val(lower, cloog_int_to_isl_val(isl_constraint_get_ctx(stride_c), stride->stride));
 	lower = isl_aff_ceil(lower);
-	lower = isl_aff_scale(lower, stride->stride);
+	lower = isl_aff_scale_val(lower, cloog_int_to_isl_val(isl_constraint_get_ctx(stride_c), stride->stride));
 	lower = isl_aff_add(lower, offset);
 	lower = isl_aff_neg(lower);
 	lower = isl_aff_add_coefficient_si(lower, isl_dim_in, level - 1, 1);
