# New ports collection makefile for:    afio
# Date created:         4 October 1995
# Whom:                 Juergen Lock <nox@jelal.hb.north.de>
#
# $FreeBSD$
#

PORTNAME=	afio
PORTVERSION=	2.4.7
PORTREVISION=	1
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
	@${MKDIR} ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${PREFIX}/share/examples/afio
	@${INSTALL_DATA} ${WRKSRC}/script1/DONTDUMP ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script3/* ${PREFIX}/share/examples/afio
	@${INSTALL_SCRIPT} ${WRKSRC}/script4/* ${PREFIX}/share/examples/afio
.endif

.include <bsd.port.mk>
