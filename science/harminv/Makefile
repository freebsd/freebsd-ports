PORTNAME=	harminv
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://github.com/NanoComp/harminv/releases/download/v${DISTVERSION}/

MAINTAINER=	devel@stasyan.com
COMMENT=	Solver of harmonic inversion
WWW=		https://github.com/NanoComp/harminv/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		blaslapack fortran gmake libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
