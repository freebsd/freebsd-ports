# New ports collection makefile for:    afio
# Version required:     2.4.1
# Date created:         4 October 1995
# Whom:                 Juergen Lock <nox@jelal.hb.north.de>
#
# $Id: Makefile,v 1.5 1997/01/06 09:24:57 obrien Exp $
#

DISTNAME=       afio.2.4.2
PKGNAME=        afio-2.4.2
CATEGORIES=     sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup
EXTRACT_SUFX=   .tgz

MAINTAINER=	nox@jelal.hb.north.de

ALL_TARGET=	afio
MAN1=		afio.1


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/afio
	@(cd ${WRKSRC} ; \
		${INSTALL_MAN} README SCRIPTS ${PREFIX}/share/doc/afio)
	@${MKDIR} ${PREFIX}/share/example/afio
	@${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${PREFIX}/share/example/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script1/DONTDUMP ${PREFIX}/share/example/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${PREFIX}/share/example/afio
.endif

.include <bsd.port.mk>
