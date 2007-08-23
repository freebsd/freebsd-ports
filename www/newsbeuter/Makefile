# New ports collection makefile for:		newsbeuter
# Date created:					2007-06-01
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://synflood.at/newsbeuter/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LIB_DEPENDS=	stfl.1:${PORTSDIR}/devel/stfl \
		nxml.18:${PORTSDIR}/textproc/libnxml \
		mrss.18:${PORTSDIR}/textproc/libmrss

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_SQLITE=	yes

MAN1=	newsbeuter.1 podbeuter.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			/^CXXFLAGS/s|=|+=|; s|/usr/local|${LOCALBASE}|" \
				${WRKSRC}/Makefile

.include <bsd.port.post.mk>
