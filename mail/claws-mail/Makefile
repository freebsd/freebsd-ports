# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	claws-mail
CATEGORIES=	mail news ipv6

COMMENT=	Lightweight and very featureful GTK+ based e-mail and news client

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		etpan:${PORTSDIR}/mail/libetpan \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_GNOME=	gtk20
USES=		iconv pathfix pkgconfig
INSTALLS_ICONS=	yes

MAN1=		claws-mail.1

OPTIONS_DEFINE=	COMPFACE DEBUG DOCS ENCHANT IPV6 JPILOT LDAP \
		MANUAL NLS STARTUP THEMES

COMPFACE_DESC=		X-Face support
ENCHANT_DESC=		Spell checking support
JPILOT_DESC=		JPilot support
MANUAL_DESC=		User manual
STARTUP_DESC=		Startup notification support
THEMES_DESC=		Additional themes

OPTIONS_DEFAULT=	COMPFACE ENCHANT MANUAL STARTUP THEMES

.include "Makefile.claws"
.include <bsd.port.options.mk>

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
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@Comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-maintainer-mode
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=		startup-notification-1:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=	--enable-startup-notification
.else
CONFIGURE_ARGS+=	--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MTHEMES}
RUN_DEPENDS+=	${LOCALBASE}/share/claws-mail/themes/ZX-0_1.1/down_arrow.xpm:${PORTSDIR}/x11-themes/claws-mail-themes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv||g; s|-lpisock\"|-liconv &|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g ; s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/procmime.c
	@${REINPLACE_CMD} -e "/(GPGME_LIBS)/d" \
		${WRKSRC}/src/Makefile.in
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
