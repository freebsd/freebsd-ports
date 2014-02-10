# $FreeBSD$

PORTNAME=	samplicator
PORTVERSION=	1.3.7.b6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	samplicator
DISTNAME=	samplicator-1.3.7-beta6

MAINTAINER=	me@falz.net
COMMENT=	Receives UDP datagrams and redistributes them to a set of receivers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/samplicate
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS 

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samplicate ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
