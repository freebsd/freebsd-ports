# New ports collection makefile for:	sed_inplace
# Date created:				17 June 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sed_inplace
PORTVERSION=	2002.06.17
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	sobomax@FreeBSD.org

NO_WRKSUBDIR=	yes

MAKEFILE=	${PKGDIR}/src/Makefile
MAKE_ENV=	PKGDIR="${PKGDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500033
IGNORE=		"is in the base system"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sed_inplace ${PREFIX}/bin

.include <bsd.port.post.mk>
