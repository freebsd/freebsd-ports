PORTNAME=	beid
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.21
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belgian eID middleware
WWW=		https://github.com/Fedict/eid-mw/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_cxx_compile_stdcxx_11.m4:devel/autoconf-archive
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libgpg-error.so:security/libgpg-error \
		libpcsclite.so:devel/pcsc-lite \
		libproxy.so:net/libproxy
RUN_DEPENDS=	pinentry:security/pinentry

USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Fedict
GH_PROJECT=	eid-mw
USE_GNOME=	gtk30 libxml2
GLIB_SCHEMAS=	eid-viewer.gschema.xml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-p11kit \
		--disable-static \
		--enable-webextension \
		--with-gtkvers=3 \
		--with-mozext=${PREFIX}/lib/firefox/distribution/extensions \
		SSL_CFLAGS="-I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_PREFIX="${OPENSSLBASE}"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${ECHO_CMD} ${DISTVERSION}-${GH_TAGNAME} > ${WRKSRC}/.version
	@${REINPLACE_CMD} -e 's,/usr/bin/pinentry,${LOCALBASE}/bin/pinentry,' \
		-e 's,/proc/%d/exe,/proc/%d/file,' \
		${WRKSRC}/cardcomm/pkcs11/src/dialogs/dialogspinentry/dlgs_pinentry.cpp
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' \
		-e '/^LIBS=/s,=.*,=${PREFIX}/lib,' \
		${WRKSRC}/plugins_tools/chrome_pkcs11/beid-update-nssdb
	@${REINPLACE_CMD} '/^Exec=/s,/usr/bin,${PREFIX}/bin,' \
		${WRKSRC}/plugins_tools/chrome_pkcs11/beid-update-nssdb.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pkcs11
	${LN} -s ../libbeidpkcs11.so.0 \
		${STAGEDIR}${PREFIX}/lib/pkcs11/beidpkcs11.so
	${MKDIR} ${STAGEDIR}${PREFIX}/share/p11-kit/modules
	${INSTALL_DATA} ${WRKSRC}/cardcomm/pkcs11/src/beid.module \
		${STAGEDIR}${PREFIX}/share/p11-kit/modules

post-install-NLS-on:
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@boldquot/LC_MESSAGES
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@boldquot
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@quot/LC_MESSAGES
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@quot

.include <bsd.port.mk>
