include ${PETSC_DIR}/lib/petsc/conf/variables

libhpddm_petsc:
	${CXX} ${CXX_FLAGS} ${PETSC_CC_INCLUDES} \
		-I${SLEPC_DIR}/include -I${SLEPC_DIR}/${PETSC_ARCH}/include \
		${HPDDM_SRC} -shared -Wl,-soname,libhpddm_petsc.so \
		-Wl,-rpath,${PREFIX}/lib -lslepc -lpetsc \
		${PETSC_EXTERNAL_LIB_BASIC} \
		-o ${WRKLIB}/libhpddm_petsc.${SL_LINKER_SUFFIX}
