# $FreeBSD$

PORTNAME=	jackett
PORTVERSION=	0.17.568
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Jackett/Jackett/releases/download/
DISTNAME=	v${PORTVERSION}/Jackett.Binaries.Mono

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Torznab proxy implementation of the Newznab API

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	mono>0:lang/mono

USE_RC_SUBR=	jackett

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Jackett

USERS=		jackett
GROUPS=		jackett

NOARCH=		yes

post-patch:
	@${RM} ${WRKSRC}/install_service_macos ${WRKSRC}/install_service_systemd.sh

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
