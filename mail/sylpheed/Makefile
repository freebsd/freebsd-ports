# Created by: shigeri <shigeri@m10.alpha-net.ne.jp>
# $FreeBSD$

PORTNAME=	sylpheed
PORTVERSION=	3.7.0
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/v${PORTVERSION:C/\.[^\.]*$//}/  \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight, featureful, and fast GTK+ based e-mail client

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gettext gmake gnome iconv libtool pkgconfig \
		tar:bzip2
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-ipv6 \
		--prefix=${PREFIX} \
		--program-transform-name=''

CONFLICTS=	sylpheed-1.[0-8]* sylpheed-2.[0-9]* sylpheed-gtk2-[0-9]*

OPTIONS_DEFINE=	CA_BUNDLE COMPFACE CURL DOCS GPGME GTKSPELL LDAP \
		ONIGURUMA SSL HIDE_OSSIG

CA_BUNDLE_DESC=	Include CA bundle for certificate verification
COMPFACE_DESC=	X-Face support
CURL_DESC=	libcurl dependency (remote update check)
GPGME_DESC=	GnuPG support using GPGME
GTKSPELL_DESC=	Spell checking support
HIDE_OSSIG_DESC=Hide OS and GTK signature in mail header
ONIGURUMA_DESC=	Oniguruma support

OPTIONS_DEFAULT=CA_BUNDLE CURL GTKSPELL GPGME SSL

CA_BUNDLE_RUN_DEPENDS=		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

COMPFACE_LIB_DEPENDS=		libcompface.so:mail/faces
COMPFACE_CONFIGURE_ENABLE=	compface

CURL_RUN_DEPENDS=		curl:ftp/curl

GPGME_LIB_DEPENDS=		libgpgme.so:security/gpgme \
				libgpg-error.so:security/libgpg-error \
				libassuan.so:security/libassuan
GPGME_RUN_DEPENDS=		gpg:security/gnupg
GPGME_CONFIGURE_ENABLE=		gpgme

GTKSPELL_LIB_DEPENDS=		libgtkspell.so:textproc/gtkspell \
				libenchant.so:textproc/enchant \
				libdbus-glib-1.so:devel/dbus-glib \
				libdbus-1.so:devel/dbus
GTKSPELL_CONFIGURE_ENABLE=	gtkspell

HIDE_OSSIG_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_main.c

LDAP_CONFIGURE_ENABLE=		ldap
LDAP_USE=			openldap=yes

ONIGURUMA_LIB_DEPENDS=		libonig.so:devel/oniguruma
ONIGURUMA_CONFIGURE_ENABLE=	oniguruma

SSL_CONFIGURE_ENABLE=		ssl
SSL_USES=			ssl

.include <bsd.port.options.mk>

MAKEFILES=	Makefile.in ac/Makefile.in faq/Makefile.in faq/de/Makefile.in \
		faq/en/Makefile.in faq/es/Makefile.in faq/fr/Makefile.in \
		faq/it/Makefile.in manual/Makefile.in manual/en/Makefile.in \
		manual/ja/Makefile.in src/Makefile.in libsylph/Makefile.in \
		src/icons/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv||g; s|-lpisock\"|${ICONV_LIB} &|g;' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC}/libsylph/procmime.c

# to prevent breaking cc of ldif.c because of a base64.h in PREFIX/include
	@${REINPLACE_CMD} -e 's|^\(DEFS.*\.\.\)$$|\1 -I../libsylph|' \
		${WRKSRC}/src/Makefile.in

.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/manual faq//' \
		${WRKSRC}/Makefile.in
.else
.for i in ${MAKEFILES}
	@${REINPLACE_CMD} -e 's|^faqdir = @faqdir@$$|faqdir = ${DOCSDIR}/faq|g; \
		s|^manualdir = @manualdir@$$|manualdir = ${DOCSDIR}/manual|g' \
		${WRKSRC}/${i}
.endfor
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${i}.ja ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/sylpheed.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
