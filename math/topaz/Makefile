# New ports collection makefile for:	topaz
# Date created:				29 July 1997
# Whom:					Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	topaz
PORTVERSION=	3.25
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/
DISTFILES=	topaz-3_25-src.tar.gz

MAINTAINER=	issei@jp.FreeBSD.ORG

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		ncurses.4:${PORTSDIR}/devel/ncurses

CXX?=		c++
MAKEFILE=	Makefile.freebsd
USE_XLIB=	yes

post-install:
		${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${PREFIX}/bin/topaz

.include <bsd.port.mk>
