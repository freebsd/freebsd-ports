# New ports collection makefile for:	topaz
# Version required:			3.22
# Date created:				29 July 1997
# Whom:					Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	topaz-3_22-src
PKGNAME=	topaz-3.22
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/

MAINTAINER=	issei@jp.FreeBSD.ORG

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		ncurses.4:${PORTSDIR}/devel/ncurses

CXX?=		c++
MAKEFILE=	Makefile.freebsd
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
#TOPAZDIR=	${PREFIX}/libexec/topaz

post-install:
		${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${PREFIX}/bin/topaz

.include <bsd.port.mk>
