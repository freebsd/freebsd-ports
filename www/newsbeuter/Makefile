# New ports collection makefile for:		newsbeuter
# Date created:					2007-06-01
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	http://newsbeuter.org/downloads/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LIB_DEPENDS=	stfl.1:${PORTSDIR}/devel/stfl \
		curl.6:${PORTSDIR}/ftp/curl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_SQLITE=	yes
USE_RUBY=	yes
USE_GCC=	4.2+
USE_GNOME=	libxml2

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
	${REINPLACE_CMD} -e 's,<ncursesw/ncurses.h>,<ncurses.h>,' \
		${WRKSRC}/src/controller.cpp ${WRKSRC}/src/view.cpp

.include <bsd.port.post.mk>
