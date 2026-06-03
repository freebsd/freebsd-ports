--- src/smith/physics/solid_mechanics_contact.hpp.orig	2026-03-31 21:05:46.118045000 -0700
+++ src/smith/physics/solid_mechanics_contact.hpp	2026-03-31 21:06:54.640503000 -0700
@@ -331,10 +331,14 @@
       amgf_prec->SetFilteredSubspaceTransferOperator(*(contact_dof_prolongation_.get()));
       // set the filteredsubspace solver component of AMGF
       // better solution: retrieve print level from .preconditioner_print_level from linear_solver_options
+#ifdef MFEM_USE_STRUMPACK
       int filter_solver_print_level = 0;
       filter_solver_ =
           std::make_unique<StrumpackSolver>(filter_solver_print_level, contact_dof_prolongation_->GetComm());
       amgf_prec->SetFilteredSubspaceSolver(*filter_solver_.get());
+#else
+      SLIC_ERROR_ROOT("AMGFContact requires STRUMPACK support in MFEM (MFEM_USE_STRUMPACK)");
+#endif
 
       auto& lin_solver = nonlin_solver_->linearSolver();
       auto iterative_solver = dynamic_cast<mfem::IterativeSolver*>(&lin_solver);
