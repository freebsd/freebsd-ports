# New ports collection makefile for:		spiped secure pipe daemon
# Date created:					2011-08-18
# Whom:						Colin Percival
#
# $FreeBSD$
#

PORTNAME=	spiped
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Daemon for creating secure symmetric pipes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

PLIST_FILES=	bin/spiped
PORTDOCS=	BUILDING CHANGELOG COPYRIGHT README STYLE

USE_RC_SUBR=	spiped

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
