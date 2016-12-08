# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	gtkfind
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/ \
		http://www.purplehat.org/downloads/gtkfind/

MAINTAINER=	perryh@pluto.rain.com
COMMENT=	GTK front-end to find(1)

LICENSE=	GPLv2

BUILD_DEPENDS=	appres:x11/appres \
		xterm:x11/xterm

USES=		gmake
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gtkfind \
		man/man1/gtkfind.1.gz

post-patch:
	${REINPLACE_CMD} -e "s,-O2,${CFLAGS}," ${WRKSRC}/configure ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkfind ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtkfind.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
