# New ports collection makefile for:	topaz
# Date created:				29 July 1997
# Whom:					Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	topaz
PORTVERSION=	3.30
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}-src

MAINTAINER=	issei@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

.include<bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses:${PORTSDIR}/devel/ncurses
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
MAKEFILE=	Makefile.freebsd

post-install:
	${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${PREFIX}/bin/topaz

.include <bsd.port.post.mk>
