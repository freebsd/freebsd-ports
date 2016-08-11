# Compiler settings required for R and the R-cran ports.
.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} < 1000015
USE_GCC=	yes
.  endif
.else
.  if ${OPSYS} == DragonFly
USE_GCC=	6
.  endif
.endif
