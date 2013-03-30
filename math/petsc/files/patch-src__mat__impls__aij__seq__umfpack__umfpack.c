--- src/mat/impls/aij/seq/umfpack/umfpack.c.orig	2013-03-30 09:30:52.000000000 -0400
+++ src/mat/impls/aij/seq/umfpack/umfpack.c	2013-03-30 09:32:20.000000000 -0400
@@ -153,7 +153,7 @@
   PetscErrorCode ierr;
   int          m=A->rmap.n,n=A->cmap.n,*ai=mat->i,*aj=mat->j,status,*ra,idx;
   PetscScalar *av=mat->a;
-  const char  *strategy[]={"AUTO","UNSYMMETRIC","SYMMETRIC","2BY2"},
+  const char  *strategy[]={"AUTO","UNSYMMETRIC","SYMMETRIC"},
               *scale[]={"NONE","SUM","MAX"}; 
   PetscTruth  flg;
   
@@ -189,14 +189,12 @@
     case 0: lu->Control[UMFPACK_STRATEGY] = UMFPACK_STRATEGY_AUTO; break;
     case 1: lu->Control[UMFPACK_STRATEGY] = UMFPACK_STRATEGY_UNSYMMETRIC; break;
     case 2: lu->Control[UMFPACK_STRATEGY] = UMFPACK_STRATEGY_SYMMETRIC; break;
-    case 3: lu->Control[UMFPACK_STRATEGY] = UMFPACK_STRATEGY_2BY2; break;
     }
   }
   ierr = PetscOptionsReal("-mat_umfpack_dense_col","Control[UMFPACK_DENSE_COL]","None",lu->Control[UMFPACK_DENSE_COL],&lu->Control[UMFPACK_DENSE_COL],PETSC_NULL);CHKERRQ(ierr);
   ierr = PetscOptionsReal("-mat_umfpack_dense_row","Control[UMFPACK_DENSE_ROW]","None",lu->Control[UMFPACK_DENSE_ROW],&lu->Control[UMFPACK_DENSE_ROW],PETSC_NULL);CHKERRQ(ierr);
   ierr = PetscOptionsReal("-mat_umfpack_amd_dense","Control[UMFPACK_AMD_DENSE]","None",lu->Control[UMFPACK_AMD_DENSE],&lu->Control[UMFPACK_AMD_DENSE],PETSC_NULL);CHKERRQ(ierr);
   ierr = PetscOptionsReal("-mat_umfpack_block_size","Control[UMFPACK_BLOCK_SIZE]","None",lu->Control[UMFPACK_BLOCK_SIZE],&lu->Control[UMFPACK_BLOCK_SIZE],PETSC_NULL);CHKERRQ(ierr);
-  ierr = PetscOptionsReal("-mat_umfpack_2by2_tolerance","Control[UMFPACK_2BY2_TOLERANCE]","None",lu->Control[UMFPACK_2BY2_TOLERANCE],&lu->Control[UMFPACK_2BY2_TOLERANCE],PETSC_NULL);CHKERRQ(ierr);
   ierr = PetscOptionsReal("-mat_umfpack_fixq","Control[UMFPACK_FIXQ]","None",lu->Control[UMFPACK_FIXQ],&lu->Control[UMFPACK_FIXQ],PETSC_NULL);CHKERRQ(ierr);
   ierr = PetscOptionsReal("-mat_umfpack_aggressive","Control[UMFPACK_AGGRESSIVE]","None",lu->Control[UMFPACK_AGGRESSIVE],&lu->Control[UMFPACK_AGGRESSIVE],PETSC_NULL);CHKERRQ(ierr);
 
@@ -291,7 +289,6 @@
   ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_DENSE_ROW]: %g\n",lu->Control[UMFPACK_DENSE_ROW]);CHKERRQ(ierr);
   ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_AMD_DENSE]: %g\n",lu->Control[UMFPACK_AMD_DENSE]);CHKERRQ(ierr);
   ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_BLOCK_SIZE]: %g\n",lu->Control[UMFPACK_BLOCK_SIZE]);CHKERRQ(ierr);
-  ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_2BY2_TOLERANCE]: %g\n",lu->Control[UMFPACK_2BY2_TOLERANCE]);CHKERRQ(ierr);
   ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_FIXQ]: %g\n",lu->Control[UMFPACK_FIXQ]);CHKERRQ(ierr);
   ierr = PetscViewerASCIIPrintf(viewer,"  Control[UMFPACK_AGGRESSIVE]: %g\n",lu->Control[UMFPACK_AGGRESSIVE]);CHKERRQ(ierr);
 
