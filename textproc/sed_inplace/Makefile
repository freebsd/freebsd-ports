# New ports collection makefile for:	sed_inplace
# Date created:				17 June 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sed_inplace
PORTVERSION=	2002.10.19
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modified version of the sed(1) which can do in-place editing of files

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/sed_inplace

MAKEFILE=	${PKGDIR}/src/Makefile
MAKE_ENV=	PKGDIR="${PKGDIR}"

.ifdef USE_REINPLACE
.error You have `USE_REINPLACE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500033
#IGNORE=		"is in the base system"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sed_inplace ${PREFIX}/bin

.include <bsd.port.post.mk>
