# Ports collection makefile for:	ccxstream
# Date created:				2004-08-14
# Whom:					Michael Handler <handler@grendel.net>
#
# $FreeBSD$
#

PORTNAME=		ccxstream
PORTVERSION=		1.0.15
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xbplayer

MAINTAINER=		handler@grendel.net
COMMENT=		Stream media files to XBox Media Center via XBMSP

USE_GMAKE=		yes

USE_RC_SUBR=		yes
RC_SCRIPTS_SUB=		PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}
SAMPLERC=		${PORTNAME}.sh.sample
REALRC=			${SAMPLERC:S/.sample//}

PLIST_FILES=		bin/ccxstream bin/ccxtest etc/rc.d/${REALRC}

.if !defined(NOPORTDOCS)
PORTDOCS=		README ChangeLog TODO xbmsp-xml.txt xbmsp.txt
.endif

post-build:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/ccxstream ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/ccxtest ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/${SAMPLERC} ${PREFIX}/etc/rc.d/${REALRC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
