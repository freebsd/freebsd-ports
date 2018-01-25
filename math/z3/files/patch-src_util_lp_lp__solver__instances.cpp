--- src/util/lp/lp_solver_instances.cpp.orig	2018-01-23 13:13:30 UTC
+++ src/util/lp/lp_solver_instances.cpp
@@ -34,6 +34,8 @@ template void lp::lp_solver<double, doub
 template bool lp::lp_solver<double, double>::problem_is_empty();
 template void lp::lp_solver<double, double>::scale();
 template void lp::lp_solver<double, double>::set_scaled_cost(unsigned int);
+template std::string lp::lp_solver<double, double>::get_column_name(unsigned int) const;
+template std::string lp::lp_solver<rational, rational>::get_column_name(unsigned int) const;
 template lp::lp_solver<double, double>::~lp_solver();
 template void lp::lp_solver<lp::mpq, lp::mpq>::add_constraint(lp::lp_relation, lp::mpq, unsigned int);
 template void lp::lp_solver<lp::mpq, lp::mpq>::cleanup();
