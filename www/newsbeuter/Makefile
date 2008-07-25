# New ports collection makefile for:		newsbeuter
# Date created:					2007-06-01
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://synflood.at/newsbeuter/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	stfl.1:${PORTSDIR}/devel/stfl \
		curl.4:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_SQLITE=	yes
USE_RUBY=	yes

MAN1=	newsbeuter.1 podbeuter.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			s|/usr/local|${LOCALBASE}|; s|ruby1.8|ruby18|" \
				${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s,#include <alloca.h>,," ${WRKSRC}/src/logger.cpp

.include <bsd.port.post.mk>
