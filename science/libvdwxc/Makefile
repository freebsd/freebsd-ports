PORTNAME=	libvdwxc
DISTVERSION=	0.5.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Van der Waals density functional (DFT) library
WWW=		https://libvdwxc.org/ \
		https://gitlab.com/libvdwxc/libvdwxc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		autoreconf gmake libtool localbase
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CONFIGURE_ARGS=	--without-mpi # --with-mpi needs math/fftw3 to be configured with OPENMPI=ON

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} lib/libvdwxc.so.0.0.0 lib/libvdwxcfort.so.0.0.0

.include <bsd.port.mk>
