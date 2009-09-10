# New ports collection makefile for:	flashrom
# Date created:				06 May 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	flashrom
PORTVERSION=	0.9.1
CATEGORIES=	sysutils
MASTER_SITES=	http://qa.coreboot.org/releases/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A utility for reading, writing, verifying and erasing flash ROM chips

LIB_DEPENDS=	pci.2:${PORTSDIR}/devel/libpci

USE_BZIP2=	yes
USE_GMAKE=	yes

ONLY_FOR_ARCHS=	amd64 i386

PORTDOCS=	COPYING README
PLIST_FILES=	bin/${PORTNAME}

.if !defined(NO_INSTALL_MANPAGES)
MAN8=		${PORTNAME}.8
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${MKDIR} ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
