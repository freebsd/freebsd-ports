# $FreeBSD$

PORTNAME=	dino
PORTVERSION=	0.0.20190220
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern XMPP Chat Client using GTK+/Vala

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libgee-0.8.so:devel/libgee \
		libicuuc.so:devel/icu \
		libsoup-2.4.so:devel/libsoup

OPTIONS_DEFINE=	OMEMO UPLOAD GNUPG
OPTIONS_DEFAULT=	OMEMO UPLOAD GNUPG
OPTIONS_SUB=	yes

USES=		cmake desktop-file-utils gettext-tools gnome \
		ninja pkgconfig

USE_GITHUB=	yes
GH_TAGNAME=	6de86c27
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	SHARED_SIGNAL_PROTOCOL=yes
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-Wl,--export-dynamic
INSTALLS_ICONS=	yes

USE_GNOME=	cairo gdkpixbuf2 glib20 gnomeprefix gtk30 intlhack

OMEMO_DESC=	OMEMO plugin
UPLOAD_DESC=	HTTP file upload plugin
OMEMO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libqrencode.so:graphics/libqrencode \
			libsignal-protocol-c.so:net/libsignal
OMEMO_VARS=		ENABLED_PLUGINS+=omemo
OMEMO_VARS_OFF=	DISABLED_PLUGINS+=omemo
UPLOAD_VARS=		ENABLED_PLUGINS+=http-files
UPLOAD_VARS_OFF=	DISABLED_PLUGINS+=http-files
GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme
GNUPG_VARS=		ENABLED_PLUGINS+=openpgp
GNUPG_VARS_OFF=	DISABLED_PLUGINS+=openpgp

CMAKE_ARGS+=	-DENABLED_PLUGINS="${ENABLED_PLUGINS:S/ /;/gW}"
CMAKE_ARGS+=	-DDISABLED_PLUGINS="${DISABLED_PLUGINS:S/ /;/gW}"

pre-everything::
	@if [ -z "${PACKAGE_BUILDING}" ]; then if ! ${PKG_BIN} query \
			'%o-%Ok-%Od' databases/sqlite3 | \
			${GREP} -F -wq databases/sqlite3-UNICODE61-on; then \
		${ECHO_MSG} "/!\ Please make sure databases/sqlite3 is built\
			       with UNICODE61 option"; \
	exit 1; \
	fi; fi

.include <bsd.port.mk>
