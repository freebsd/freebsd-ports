# $FreeBSD$

PORTNAME=	samplicator
PORTVERSION=	1.3.7.b6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	samplicator-1.3.7-beta6

MAINTAINER=	me@falz.net
COMMENT=	Receives UDP datagrams and redistributes them to a set of receivers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable (google code has gone away)

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
