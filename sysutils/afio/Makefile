# New ports collection makefile for:    afio
# Date created:         4 October 1995
# Whom:                 Juergen Lock <nox@jelal.hb.north.de>
#
# $FreeBSD$
#

PORTNAME=	afio
PORTVERSION=	2.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archiver & backup program w/ builtin compression

ALL_TARGET=	${PORTNAME}
MAN1=		afio.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_MAN} README SCRIPTS ${DOCSDIR})
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/script1/DONTDUMP ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/script3/* ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/script4/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
