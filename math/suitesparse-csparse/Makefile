PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	4.3.0
CATEGORIES=	math

COMMENT=	Concise Sparse Matrix package
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

USES=		localbase:ldflags

MPORTNAME=	CSparse
USE_LDCONFIG=	yes
PLIST_FILES=	# empty

# For system-wide installation, the author recommends that you install
# CXSparse instead.
# The CSparse library is meant for personal experimentation.  The 'make
# install' in this Makefile only installs a static compiled library in
# CSparse/Lib.  It does not install it for system-wide usage.
do-install:
	${DO_NADA}

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
