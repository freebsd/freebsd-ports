PORTNAME=	gq
PORTVERSION=	1.3.4
PORTREVISION=	19
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}client/GQ%20Unstable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based LDAP client
WWW=		https://sourceforge.net/projects/gqclient/

LICENSE=	GPLv2+ LGPL21+ # some source files are under lgpl
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

DEPRECATED=	Upstream last release was in 2008
EXPIRATION_DATE=	2024-01-24

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libgnome-keyring.so:security/libgnome-keyring \
		libgpg-error.so:security/libgpg-error \
		libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext gmake gnome iconv ldap localbase \
		pkgconfig shared-mime-info ssl
USE_GNOME=	cairo intltool gdkpixbuf2 libglade2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE} --disable-update-mimedb

CPPFLAGS+=	-Wno-return-type
LIBS+=		-lcrypto

OPTIONS_DEFINE=	DND CACHE
OPTIONS_DEFAULT=	DND CACHE

CACHE_DESC=	Support the OpenLDAP experimental client cache
DND_DESC=	Enable Drag and drop support in browse mode

CACHE_CONFIGURE_ENABLE=	cache
DND_CONFIGURE_ENABLE=	browser-dns

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
BROKEN=	Fails to build with OpenSSL 1.1.1t and later
BROKEN_SSL=	base openssl openssl111 openssl31
BROKEN_SSL_REASON=	Fails to build with OpenSSL 1.1.1t and later
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/syntax.h \
		${WRKSRC}/src/glib-helpers.[ch] \
		${WRKSRC}/src/gq-hash.h \
		${WRKSRC}/src/gq-main-loop.h \
		${WRKSRC}/src/gq-stack.[ch] \
		${WRKSRC}/src/gq-tab.h

.include <bsd.port.post.mk>
