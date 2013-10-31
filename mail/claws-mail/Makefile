# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	claws-mail
PORTREVISION=	1
CATEGORIES=	mail news ipv6

COMMENT=	Lightweight and featureful GTK+ based e-mail and news client

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libetpan.so:${PORTSDIR}/mail/libetpan \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_GNOME=	gtk20
USES=		pathfix
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	COMPFACE DEBUG DOCS ENCHANT IPV6 JPILOT LDAP \
		MANUAL NLS STARTUP THEMES
OPTIONS_SUB=	yes

COMPFACE_DESC=		X-Face support
ENCHANT_DESC=		Spell checking support
JPILOT_DESC=		JPilot support
MANUAL_DESC=		User manual
STARTUP_DESC=		Startup notification support
THEMES_DESC=		Additional themes

OPTIONS_DEFAULT=	COMPFACE ENCHANT MANUAL STARTUP THEMES

COMPFACE_CONFIGURE_ENABLE=	compface
COMPFACE_LIB_DEPENDS=	libcompface.so:${PORTSDIR}/mail/faces

DEBUG_CONFIGURE_ON=	--enable-maintainer-mode

ENCHANT_CONFIGURE_ENABLE=	enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant

IPV6_CONFIGURE_ENABLE=	ipv6

JPILOT_CONFIGURE_ENABLE=	jpilot
JPILOT_LIB_DEPENDS=	libpisock.so:${PORTSDIR}/palm/pilot-link
JPILOT_RUN_DEPENDS=	jpilot:${PORTSDIR}/palm/jpilot

LDAP_CONFIGURE_ENABLE=	ldap

MANUAL_CONFIGURE_ON=	--enable-manual --with-manualdir=${DOCSDIR}/manual
MANUAL_CONFIGURE_OFF=	--disable-manual
MANUAL_BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2html:${PORTSDIR}/textproc/docbook-utils

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification

THEMES_RUN_DEPENDS=	${LOCALBASE}/share/claws-mail/themes/ZX-0_1.1/down_arrow.xpm:${PORTSDIR}/x11-themes/claws-mail-themes

.include "Makefile.claws"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv||g; s|-lpisock\"|${ICONV_LIB} &|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g ; s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/procmime.c
	@${REINPLACE_CMD} -e "/(GPGME_LIBS)/d" \
		${WRKSRC}/src/Makefile.in
	@for f in `${FIND} ${WRKSRC}/tools -type f -print`; do \
		${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" $$f; done

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in NEWS RELEASE_NOTES README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/README ${STAGEDIR}${DOCSDIR}/README.tools
	@${MKDIR} ${STAGEDIR}${DATADIR}
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
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
