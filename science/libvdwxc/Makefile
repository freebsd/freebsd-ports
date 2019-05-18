# $FreeBSD$

PORTNAME=	libvdwxc
DISTVERSION=	0.4.6.20190510
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Van der Waals density functional (DFT) library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		autoreconf gmake libtool localbase
GNU_CONFIGURE=	yes
USE_GITLAB=	yes
GL_COMMIT=	b1e0dd854310410012d05daf4c6661b49f31b2ab
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} lib/libvdwxc.so.0.0.0 lib/libvdwxcfort.so.0.0.0

.include <bsd.port.mk>
