# Ports collection makefile for:	heirloom-sh
# Date created:				2008-03-28
# Whom:					Danijel Tasov <danielt@pilgerer.org>
#
# $FreeBSD$
#

PORTNAME=	heirloom-sh
PORTVERSION=	050706
CATEGORIES=	shells
MASTER_SITES=	SF/heirloom/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danielt@pilgerer.org
COMMENT=	Portable version of OpenSolaris' Bourne Shell

USE_BZIP2=	yes
MAN1=		jsh.1
PLIST_FILES=	bin/jsh
PORTDOCS=	CALDERA.LICENSE OPENSOLARIS.LICENSE CHANGES README

PKGINSTALL=	pkg-install
PKGDEINSTALL=	pkg-deinstall

do-build:
	cd ${WRKSRC} && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sh.1.out ${MANPREFIX}/man/man1/jsh.1

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
