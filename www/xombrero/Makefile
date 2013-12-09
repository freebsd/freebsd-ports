# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	xombrero
PORTVERSION=	1.6.3
CATEGORIES=	www
MASTER_SITES=	https://opensource.conformal.com/snapshots/xombrero/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Minimalists vi-like web browser based on webkit and GTK+

LICENSE=	ISCL

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		soup-2.4:${PORTSDIR}/devel/libsoup

USES=		pkgconfig perl5
USE_PERL5=	build
INSTALLS_ICONS=	yes

BUILD_WRKSRC=	${WRKSRC}/freebsd

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=GTK2 GTK3
OPTIONS_DEFAULT=GTK3

SUB_FILES=	xombrero

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800041
BROKEN=		does not build due to missing arc4random_buf in libc
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
LIB_DEPENDS+=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
MAKE_ENV+=	GTK_VERSION="gtk2"
.else # GTK3
USE_GNOME=	gtk30
LIB_DEPENDS+=	webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3
MAKE_ENV+=	GTK_VERSION="gtk3"
.endif

post-patch:
	@cd ${WRKSRC}; ${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|# ssl_ca_file|ssl_ca_file|' \
		-e 's|/etc/ssl/cert.pem|${LOCALBASE}/share/certs/ca-root-nss.crt|' \
			unix.c xombrero.conf
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/xombrero ${STAGEDIR}${PREFIX}/bin/xombrero
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/xombrero ${STAGEDIR}${PREFIX}/bin/xombrero-bin
	${INSTALL_MAN} ${WRKSRC}/xombrero.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.for i in 16 32 48 64 128
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA}  ${WRKSRC}/xombreroicon${i}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for i in hsts-preload style.css tld-rules
	${INSTALL_DATA}  ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA}  ${WRKSRC}/xombrero.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in favorites xombrero.conf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/playflash.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
