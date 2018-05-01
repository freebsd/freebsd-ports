# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	2.2.7
DISTVERSIONPREFIX=v
CATEGORIES=	print

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Common UNIX Printing System

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE.txt

CONFLICTS=	LPRng-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	apple

DESTDIRNAME=	DSTROOT
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dnssd						\
		--disable-gssapi					\
		--disable-launchd					\
		--disable-systemd					\
		--with-cups-user=${USERS}				\
		--with-cups-group=${GROUPS}				\
		--with-system-groups=wheel				\
		--with-dbusdir="${PREFIX}/etc/dbus-1"			\
		--with-icondir="${PREFIX}/share/icons"			\
		--with-menudir="${DESKTOPDIR}"				\
		--with-printcap="${PREFIX}/etc/printcap"		\
		--with-rcdir=no						\
		--with-optim=" "					\
		--with-pam-module="unix"				\
		ac_cv_path_JAVA= ac_cv_path_PERL= ac_cv_path_PHPCGI=	\
		ac_cv_path_PHP= ac_cv_path_PYTHON=
USES=		cpe gmake iconv localbase pkgconfig
CPE_VENDOR=	apple
USE_LDCONFIG=	yes
USE_RC_SUBR=	cupsd

GROUPS=		cups
USERS=		cups

OPTIONS_DEFINE=		AVAHI DBUS DOCS GNUTLS IPPTOOL LIBPAPER NLS X11
OPTIONS_DEFAULT=	AVAHI DBUS GNUTLS LIBPAPER
OPTIONS_SUB=		yes

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_SUB_LIST=		AVAHI_DAEMON=avahi_daemon
AVAHI_SUB_LIST_OFF=	AVAHI_DAEMON=

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus
DBUS_SUB_LIST=		DBUS_DAEMON=dbus
DBUS_SUB_LIST_OFF=	DBUS_DAEMON=

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--enable-gnutls
GNUTLS_CONFIGURE_OFF=	--disable-ssl

IPPTOOL_DESC=		Internet Printing Protocol testing tool

LIBPAPER_LIB_DEPENDS=	libpaper.so:print/libpaper
LIBPAPER_CONFIGURE_ENABLE=libpaper

X11_DESC=		Install desktop menu item
X11_BUILD_DEPENDS=	xdg-open:devel/xdg-utils
X11_RUN_DEPENDS=	xdg-open:devel/xdg-utils

.if defined(CUPS_OVERWRITE_BASE)
PLIST_SUB+=	OVERWRITE=""
.else
PLIST_SUB+=	OVERWRITE="@comment "
.endif

.if exists(/usr/lib/libusb.so)
PLIST_SUB+=	USB=""
.else
PLIST_SUB+=	USB="@comment "
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_search_libiconv_open=no
.endif

post-patch:
	@${REINPLACE_CMD} -e '/SILENT/d' ${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} 's/usblp/ulpt/g' ${WRKSRC}/backend/usb-libusb.c
	@${REINPLACE_CMD} -e 's|/usr/local/etc/pam.d|${LOCALBASE}/etc/pam.d|' \
		-e 's/-fstack-protector//' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc ${WRKSRC}/templates -type f -exec ${SED} -i '' \
		's|http://www.cups.org|https://www.cups.org|g' {} +
	@${REINPLACE_CMD} '/stripopt=/s/-x//' ${WRKSRC}/install-sh
	@${REINPLACE_CMD} 's|/etc/cups|${LOCALBASE}/etc/cups|g' \
		${WRKSRC}/man/*.man*
	@${REINPLACE_CMD} -e 's|\.default|.sample|'\
		${WRKSRC}/cgi-bin/admin.c\
		${WRKSRC}/conf/Makefile
.if !empty(ARCH:Mpowerpc*)
	@${REINPLACE_CMD} -e 's|@PIEFLAGS@||g' ${WRKSRC}/Makedefs.in
.endif

post-patch-DOCS-off:
# Link to online documentation.
	@${FIND} ${WRKSRC}/doc ${WRKSRC}/templates -type f -exec ${SED} -i '' \
		-e 's|[Hh][Rr][Ee][Ff]="/*help/\([{"]\)|href="https://www.cups.org/documentation.html\1|g' \
		-e '/have_gssapi/s|[Hh][Rr][Ee][Ff]="/*help/|href="https\\://www.cups.org/doc/|g' \
		-e 's|[Hh][Rr][Ee][Ff]="/*help/|href="https://www.cups.org/doc/|g' {} +

post-install:
	${LN} -sf lpr ${STAGEDIR}${PREFIX}/bin/lpr-cups
	${INSTALL_DATA} ${FILESDIR}/cups.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/cups ${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.post.mk>
