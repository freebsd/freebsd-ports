# New ports collection makefile for:	pinfo
# Date created:		19 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pinfo
PORTVERSION=	0.6.8
CATEGORIES=	misc
MASTER_SITES=	http://dione.ids.pl/~pborys/software/pinfo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-readline \
		--with-localedir=${PREFIX}/share/locale

MAN1=	pinfo.1
INFO=	pinfo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
.endif

.include <bsd.port.post.mk>
