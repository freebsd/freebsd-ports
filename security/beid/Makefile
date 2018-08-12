# $FreeBSD$

PORTNAME=	beid
PORTVERSION=	4.4.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belgian eID middleware

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USE_GITHUB=	yes
GH_ACCOUNT=	Fedict
GH_PROJECT=	eid-mw

USES=		autoreconf gettext-tools gmake libtool pkgconfig
USE_GNOME=	gtk30
GLIB_SCHEMAS=	eid-viewer.gschema.xml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-p11kit --disable-static --with-gtkvers=3 \
		--enable-webextension \
		--with-mozext=${PREFIX}/lib/firefox/browser/extensions
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	@${ECHO_CMD} ${PORTVERSION}-release > ${WRKSRC}/.version
	@${REINPLACE_CMD} -e '/^MODUTIL=/s,/usr/bin,${LOCALBASE}/bin,' \
		-e '/^CERTUTIL=/s,/usr/bin,${LOCALBASE}/bin,' \
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
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@boldquot/LC_MESSAGES
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@boldquot
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@quot/LC_MESSAGES
	${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/en@quot

.include <bsd.port.mk>
