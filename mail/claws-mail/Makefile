# New ports collection makefile for:	claws-mail
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	claws-mail
PORTVERSION=	3.7.10
PORTREVISION=	1
CATEGORIES=	mail news ipv6
MASTER_SITES=	SF/sylpheed-claws/Claws%20Mail/${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A lightweight and very featureful GTK+ based e-mail and news client

LICENSE=	GPLv3

LIB_DEPENDS=	etpan:${PORTSDIR}/mail/libetpan \
		cairo:${PORTSDIR}/graphics/cairo \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		png:${PORTSDIR}/graphics/png \
		gnutls.47:${PORTSDIR}/security/gnutls \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS=	sylpheed-claws

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xcursor xdmcp xext xfixes xi xinerama xrandr \
		xrender
USE_GNOME=	gnomehack pkgconfig gtk20 glib20 atk libartlgpl2 pango libxml2
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		claws-mail.1

CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	ENCHANT		"Enable spell checking support."	on \
		BOGOFILTER	"Enable bogofilter support."		off \
		COMPFACE	"Enable X-Face support."		on \
		DEBUG		"Enable debug support."			off \
		DILLO		"Enable Dillo HTML viewer."		off \
		GPGME		"Enable PGP/GnuPG/SMIME support using GPGME."	off \
		IPV6		"Enable ipv6 support."			on \
		JPILOT		"Enable JPilot support."		off \
		LDAP		"Enable LDAP support."			off \
		MANUAL		"Build and install manual files"	on \
		SA_PLUG		"Enable SpamAssassin support."		off \
		STARTUP		"Enable startup notification support."	on \
		THEMES		"Install additional themes."		on

.include <bsd.port.pre.mk>

.if defined(WITH_BOGOFILTER)
RUN_DEPENDS+=		bogofilter:${PORTSDIR}/mail/bogofilter
CONFIGURE_ARGS+=	--enable-bogofilter-plugin
PLIST_SUB+=		BOGO_PLUG=""
.else
CONFIGURE_ARGS+=	--disable-bogofilter-plugin
PLIST_SUB+=		BOGO_PLUG="@comment "
.endif

.if defined(WITH_COMPFACE)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--enable-compface
.else
CONFIGURE_ARGS+=	--disable-compface
.endif

.if defined(WITH_ENCHANT)
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.else
CONFIGURE_ARGS+=	--disable-enchant
.endif

.if defined(WITH_JPILOT)
LIB_DEPENDS+=		pisock:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if defined(WITH_MANUAL)
BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2html:${PORTSDIR}/textproc/docbook-utils
CONFIGURE_ARGS+=	--enable-manual --with-manualdir=${DOCSDIR}/manual
PLIST_SUB+=		MANUAL=""
.else
CONFIGURE_ARGS+=	--disable-manual
PLIST_SUB+=		MANUAL="@comment "
.endif

.if defined(WITH_SA_PLUG)
RUN_DEPENDS+=		spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG=""
.else
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG="@comment "
.endif

.if defined(WITH_GPGME)
PLIST_SUB+=		GPGME=""
CONFIGURE_ARGS+=	--enable-pgpmime-plugin --enable-pgpcore-plugin \
			--enable-pgpinline-plugin --enable-smime-plugin
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme \
			gpg-error:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
.else
PLIST_SUB+=		GPGME="@comment "
CONFIGURE_ARGS+=	--disable-pgpmime-plugin --disable-pgpcore-plugin \
			--disable-pgpinline-plugin --disable-smime-plugin
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-crash-dialog
STRIP=
.endif

.if defined(WITH_DILLO)
PLIST_SUB+=	DILLO=""
RUN_DEPENDS+=	dillo:${PORTSDIR}/www/dillo
.else
PLIST_SUB+=	DILLO="@comment "
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=	--enable-startup-notification
.else
CONFIGURE_ARGS+=	--disable-startup-notification
.endif

.if !defined(WITHOUT_THEMES)
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
.if !defined(NOPORTDOCS)
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
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/claws-mail.desktop ${PREFIX}/share/applications/
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/claws-mail*.png ${PREFIX}/share/pixmaps/

.include <bsd.port.post.mk>
