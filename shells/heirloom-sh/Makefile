# Created by: Danijel Tasov <danielt@pilgerer.org>
# $FreeBSD$

PORTNAME=	heirloom-sh
PORTVERSION=	050706
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	SF/heirloom/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danielt@pilgerer.org
COMMENT=	Portable version of OpenSolaris' Bourne Shell

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		tar:bzip2
MAKEFILE=	makefile
PLIST_FILES=	"@shell bin/jsh" \
		man/man1/jsh.1.gz
PORTDOCS=	CALDERA.LICENSE OPENSOLARIS.LICENSE CHANGES README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sh.1.out ${STAGEDIR}${MANPREFIX}/man/man1/jsh.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
