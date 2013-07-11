# Created by: arved
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://newsbeuter.org/downloads/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LIB_DEPENDS=	stfl.1:${PORTSDIR}/devel/stfl \
		curl:${PORTSDIR}/ftp/curl \
		json.0:${PORTSDIR}/devel/json-c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
USES=		gettext ncurses
USE_PERL5_BUILD=yes
USE_SQLITE=	yes
USE_GNOME=	libxml2

MAN1=	newsbeuter.1 podbeuter.1

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			s|/usr/local|${LOCALBASE}|; s|ruby1.8|ruby18|" \
				${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,<ncursesw/ncurses.h>,<ncurses.h>,' \
		${WRKSRC}/src/controller.cpp ${WRKSRC}/src/view.cpp
	${REINPLACE_CMD} -e 's,fail "ncursesw5",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh

.include <bsd.port.post.mk>
