# ex:ts=8
# New ports collection makefile for:	slmon
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	slmon
PORTVERSION=	0.5.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		gtop.1:${PORTSDIR}/devel/libgtop \
		intl.2:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
LIBGTOP_CONFIG=	${LOCALBASE}/bin/libgtop-config
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lncurses -lintl -lgnugetopt"
USE_GMAKE=	yes
MAN1=	slmon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
