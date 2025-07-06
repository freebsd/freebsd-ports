PORTNAME=	rsplib
DISTVERSION=	3.5.3
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/rserpool/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	RSerPool Framework and Example Applications
WWW=		https://www.nntb.no/~dreibh/rserpool/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm:graphics/GraphicsMagick \
		pdf2svg:graphics/pdf2svg

USES=		cmake desktop-file-utils ghostscript:10,build gl qt:6 \
		shebangfix tar:xz
USE_GL=		gl opengl
USE_LDCONFIG=	yes
USE_QT=		base

SHEBANG_FILES=	src/scriptingserviceexample

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DENABLE_CSP=1 \
		-DENABLE_QT=1 \
		-DUSE_KERNEL_SCTP=1

# Work-around for build issue on ARM (https://bugs.freebsd.org/285706):
MAKE_ENV=	OMP_NUM_THREADS=1

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
