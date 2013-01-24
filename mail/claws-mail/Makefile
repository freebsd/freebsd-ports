# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	claws-mail
PORTVERSION=	3.9.0
CATEGORIES=	mail news ipv6
MASTER_SITES=	SF/sylpheed-claws/Claws%20Mail/${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Lightweight and very featureful GTK+ based e-mail and news client

LICENSE=	GPLv3

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		curl:${PORTSDIR}/ftp/curl \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		etpan:${PORTSDIR}/mail/libetpan \
		gmp:${PORTSDIR}/math/gmp \
		freetype:${PORTSDIR}/print/freetype2 \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		tasn1:${PORTSDIR}/security/libtasn1 \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS=	sylpheed-claws

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XORG=	ice pixman sm x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	atk glib20 gnomehack gtk20 libartlgpl2 libxml2 pango
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		claws-mail.1

CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} --disable-dbus
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS_DEFINE=	BOGOFILTER COMPFACE DEBUG DILLO ENCHANT GPGME IPV6 JPILOT LDAP \
		MANUAL SPAMASSASSIN STARTUP THEMES

BOGOFILTER_DESC=	Bogofilter plugin
COMPFACE_DESC=		X-Face support
DILLO_DESC=		Dillo HTML viewer plugin
ENCHANT_DESC=		Spell checking support
GPGME_DESC=		PGP/GnuPG/SMIME plugins
JPILOT_DESC=		JPilot plugin
MANUAL_DESC=		User manual
SPAMASSASSIN_DESC=	SpamAssassin plugin
STARTUP_DESC=		Startup notification support
THEMES_DESC=		Additional themes

OPTIONS_DEFAULT=	COMPFACE ENCHANT MANUAL STARTUP THEMES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOGOFILTER}
RUN_DEPENDS+=		bogofilter:${PORTSDIR}/mail/bogofilter
CONFIGURE_ARGS+=	--enable-bogofilter-plugin
PLIST_SUB+=		BOGO_PLUG=""
.else
CONFIGURE_ARGS+=	--disable-bogofilter-plugin
PLIST_SUB+=		BOGO_PLUG="@comment "
.endif

.if ${PORT_OPTIONS:MCOMPFACE}
LIB_DEPENDS+=		compface:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--enable-compface
.else
CONFIGURE_ARGS+=	--disable-compface
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.else
CONFIGURE_ARGS+=	--disable-enchant
.endif

.if ${PORT_OPTIONS:MJPILOT}
LIB_DEPENDS+=		pisock:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if ${PORT_OPTIONS:MMANUAL}
BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2html:${PORTSDIR}/textproc/docbook-utils
CONFIGURE_ARGS+=	--enable-manual --with-manualdir=${DOCSDIR}/manual
PLIST_SUB+=		MANUAL=""
.else
CONFIGURE_ARGS+=	--disable-manual
PLIST_SUB+=		MANUAL="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@Comment "
.endif

.if ${PORT_OPTIONS:MSPAMASSASSIN}
RUN_DEPENDS+=		spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG=""
.else
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG="@comment "
.endif

.if ${PORT_OPTIONS:MGPGME}
PLIST_SUB+=		GPGME=""
CONFIGURE_ARGS+=	--enable-pgpmime-plugin --enable-pgpcore-plugin \
			--enable-pgpinline-plugin --enable-smime-plugin
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme \
			gpg-error:${PORTSDIR}/security/libgpg-error \
			assuan:${PORTSDIR}/security/libassuan
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
.else
PLIST_SUB+=		GPGME="@comment "
CONFIGURE_ARGS+=	--disable-pgpmime-plugin --disable-pgpcore-plugin \
			--disable-pgpinline-plugin --disable-smime-plugin
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-maintainer-mode
.endif

.if ${PORT_OPTIONS:MDILLO}
PLIST_SUB+=	DILLO=""
RUN_DEPENDS+=	dillo:${PORTSDIR}/www/dillo
.else
PLIST_SUB+=	DILLO="@comment "
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=		startup-notification-1:${PORTSDIR}/x11/startup-notification \
			xcb-util:${PORTSDIR}/x11/xcb-util
CONFIGURE_ARGS+=	--enable-startup-notification
.else
CONFIGURE_ARGS+=	--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MTHEMES}
RUN_DEPENDS+=	${LOCALBASE}/share/claws-mail/themes/ZX-0_1.1/down_arrow.xpm:${PORTSDIR}/x11-themes/claws-mail-themes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lresolv||g; s|-lpisock\"|-liconv &|g' \
		-e 's|-DGTK_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g ; s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/procmime.c
	@${REINPLACE_CMD} -e "s|po intl src|po src| ; s:@CLAWS_GNOME2:#@CLAWS_GNOME2:g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s:-Wno-unused-function::" ${WRKSRC}/src/Makefile.in
	@for f in `${FIND} ${WRKSRC}/tools -type f -print`; do \
		${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" $$f; done

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in NEWS RELEASE_NOTES README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/tools/README ${DOCSDIR}/README.tools
.endif
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} OOo2claws-mail.pl acroread2claws-mail.pl \
		calypso_convert.pl convert_mbox.pl eud2gc.py filter_conv.pl \
		filter_conv_new.pl fix_date.sh freshmeat_search.pl \
		gif2xface.pl google_msgid.pl google_search.pl \
		kmail-mailbox2claws-mail.pl kmail2claws-mail.pl \
		kmail2claws-mail_v2.pl multiwebsearch.conf multiwebsearch.pl \
		nautilus2claws-mail.sh outlook2claws-mail.pl tb2claws-mail \
		tbird2claws.py textviewer.pl textviewer.sh \
		thunderbird-filters-convertor.pl uudec uuooffice vcard2xml.py \
		${DATADIR}

.include <bsd.port.mk>
