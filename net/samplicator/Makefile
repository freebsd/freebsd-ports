# $FreeBSD$

PORTNAME=	samplicator
DISTVERSION=	1.3.8rc1
CATEGORIES=	net

MAINTAINER=	me@falz.net
COMMENT=	Receives UDP datagrams and redistributes them to a set of receivers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	sleinen

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/samplicate
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samplicate ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
