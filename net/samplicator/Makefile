# $FreeBSD$

PORTNAME=	samplicator
PORTVERSION=	1.3.7.b6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	samplicator
DISTNAME=	samplicator-1.3.7-beta6

MAINTAINER=	me@falz.net
COMMENT=	Receives UDP datagrams and redistributes them to a set of receivers

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/samplicate
PORTDOCS=	NEWS README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samplicate ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
