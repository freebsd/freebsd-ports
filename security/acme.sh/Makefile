# $FreeBSD$

PORTNAME=	acme.sh
PORTVERSION=	2.6.9
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	ACME protocol client written in shell

LICENSE=	GPLv3+

RUN_DEPENDS=	curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Neilpang

USERS=  acme
GROUPS= acme

OPTIONS_DEFINE=	CURL DOCS WGET
OPTIONS_DEFAULT=	CURL
CURL_DESC=	Add ftp/curl as a run-time dependency
WGET_DESC=	Add ftp/wget as a run-time dependency

NO_ARCH=	yes
NO_BUILD=	yes

CURL_RUN_DEPENDS=	curl:ftp/curl
WGET_RUN_DEPENDS=	wget:ftp/wget

PLIST_FILES=	sbin/${PORTNAME}
PORTDOCS=	README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
