# New ports collection makefile for:    afio
# Version required:     2.4.5
# Date created:         4 October 1995
# Whom:                 Juergen Lock <nox@jelal.hb.north.de>
#
# $Id: Makefile,v 1.6 1997/04/01 22:09:19 fenner Exp $
#

DISTNAME=       afio-2.4.5
CATEGORIES=     sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup
EXTRACT_SUFX=   .tgz

MAINTAINER=	nox@jelal.hb.north.de

WRKSRC=		${WRKDIR}/afio.2.4.5
ALL_TARGET=	afio
MAN1=		afio.1


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/afio
	@(cd ${WRKSRC} ; \
		${INSTALL_MAN} README SCRIPTS ${PREFIX}/share/doc/afio)
	@${MKDIR} ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${PREFIX}/share/examples/afio
	@${INSTALL_DATA} ${WRKSRC}/script1/DONTDUMP ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script3/* ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script4/* ${PREFIX}/share/examples/afio
.endif

.include <bsd.port.mk>
