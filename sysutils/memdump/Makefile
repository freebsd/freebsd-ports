# Ports collection makefile for:  memdump
# Date created:			  16 June 2004
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	memdump
PORTVERSION=	1.01
CATEGORIES=	sysutils
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	onatan@gmail.com
COMMENT=	Forensic utility for memory-dumping

ALL_TARGET=	what

PLIST_FILES=	bin/memdump
PORTDOCS=	README LICENSE
MAN1=		memdump.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memdump ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memdump.1 ${MANPREFIX}/man/man1
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.	endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		unsupported FreeBSD version
.endif

.include <bsd.port.post.mk>
