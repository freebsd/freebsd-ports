PORTNAME=	ssdeep
PORTVERSION=	2.14.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/ssdeep-project/ssdeep/releases/download/release-${PORTVERSION}/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Tool for computing context triggered piecewise hashes
WWW=		https://ssdeep-project.github.io/ssdeep/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gmake libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
