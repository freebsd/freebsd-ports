# New ports collection makefile for:	flashrom
# Date created:				06 May 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	flashrom
PORTVERSION=	0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	http://qa.coreboot.org/releases/

MAINTAINER=	ports@logvinov.com
COMMENT=	A utility for reading, writing, verifying and erasing flash ROM chips

LIB_DEPENDS=	pci.2:${PORTSDIR}/devel/libpci

USE_BZIP2=	yes
USE_GMAKE=	yes

PORTDOCS=	COPYING README
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
