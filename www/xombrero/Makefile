# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	xombrero
PORTVERSION=	1.6.4
CATEGORIES=	www
MASTER_SITES=	https://opensource.conformal.com/snapshots/xombrero/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Minimalists vi-like web browser based on webkit and GTK+

LICENSE=	ISCL

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libsoup-2.4.so:devel/libsoup

BROKEN_FreeBSD_9=	does not build
BROKEN_FreeBSD_10=	does not build

USES=		desktop-file-utils pkgconfig perl5 tar:tgz
USE_PERL5=	build
INSTALLS_ICONS=	yes

BUILD_WRKSRC=	${WRKSRC}/freebsd

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2
GTK2_USE=		GNOME=gtk20
GTK2_MAKE_ENV=		GTK_VERSION="gtk2"
GTK3_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
GTK3_USE=		GNOME=gtk30
GTK3_MAKE_ENV=		GTK_VERSION="gtk3"

SUB_FILES=	xombrero
PORTEXAMPLES=	*

post-patch:
	@cd ${WRKSRC}; ${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|# ssl_ca_file|ssl_ca_file|' \
		-e 's|/etc/ssl/cert.pem|${LOCALBASE}/share/certs/ca-root-nss.crt|' \
			unix.c xombrero.conf
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/xombrero ${STAGEDIR}${PREFIX}/bin/xombrero
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/xombrero ${STAGEDIR}${PREFIX}/bin/xombrero-bin
	${INSTALL_MAN} ${WRKSRC}/xombrero.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.for i in 16 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/xombreroicon${i}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for i in favicon.ico hsts-preload style.css tld-rules torenabled.ico tordisabled.ico xombrero.css
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/xombrero.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in favorites xombrero.conf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/playflash.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
