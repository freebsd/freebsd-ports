# New ports collection makefile for:	memtest86
# Date created:		27 Mar 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	memtest86
PORTVERSION=	3.1a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.memtest86.com/

MAINTAINER=	ports@freebsd.org
COMMENT=	Stand alone memory test for x86 architecture computers

ONLY_FOR_ARCHS=	i386

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	README
PLIST_FILES=	share/${PORTNAME}/floppy.bin share/${PORTNAME}/memtest.iso.gz
PLIST_DIRS=	share/${PORTNAME}

do-build:
	@${CAT} ${FILESDIR}/pkg-message.in | ${SED} 's|%%DATADIR%%|${DATADIR}|g' > ${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/precomp.bin ${DATADIR}/floppy.bin
	${INSTALL_DATA} ${WRKSRC}/memtest.iso ${DATADIR}
	${GZIP_CMD} ${DATADIR}/memtest.iso
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
