# $FreeBSD$

PORTNAME=	mmdb2
DISTVERSION=	2.0.19
CATEGORIES=	science
MASTER_SITES=	https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/coot/dependencies/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ toolkit for working with macromolecular coordinate files

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSER

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes

.include <bsd.port.mk>
