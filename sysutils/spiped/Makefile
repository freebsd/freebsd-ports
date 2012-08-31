# New ports collection makefile for:		spiped secure pipe daemon
# Date created:					2011-08-18
# Whom:						Colin Percival
#
# $FreeBSD$
#

PORTNAME=	spiped
PORTVERSION=	1.2.1
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Daemon for creating secure symmetric pipes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

PLIST_FILES=	bin/spiped bin/spipe
PORTDOCS=	BUILDING CHANGELOG COPYRIGHT README STYLE
READMES=	spiped spipe

USE_RC_SUBR=	spiped

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})
.for README in ${READMES}
	${INSTALL_MAN} ${WRKSRC}/${README}/README ${DOCSDIR}/README-${README}
.endfor
.endif

.include <bsd.port.mk>
