# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	claws-mail
PORTREVISION=	1
CATEGORIES=	mail news ipv6

COMMENT=	Lightweight and featureful GTK+ based e-mail and news client

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libetpan.so:mail/libetpan \
		libfreetype.so:print/freetype2 \
		libsasl2.so:security/cyrus-sasl2 \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	mime-support>0:misc/mime-support

USE_XORG=	ice sm
USE_GNOME=	cairo gtk20 librsvg2
USES=		cpe desktop-file-utils pathfix python:2.7,run shebangfix ssl
SHEBANG_FILES=	tools/*.pl tools/*.py tools/tb2claws-mail
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	COMPFACE DEBUG DOCS ENCHANT IPV6 JPILOT LDAP \
		MANUAL NLS STARTUP THEMES
OPTIONS_DEFAULT=COMPFACE ENCHANT MANUAL STARTUP THEMES
OPTIONS_SUB=	yes

COMPFACE_DESC=		X-Face support
COMPFACE_CONFIGURE_ENABLE=	compface
COMPFACE_LIB_DEPENDS=	libcompface.so:mail/faces

DEBUG_CONFIGURE_ON=	--enable-maintainer-mode

ENCHANT_DESC=		Spell checking support
ENCHANT_CONFIGURE_ENABLE=	enchant
ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant

IPV6_CONFIGURE_ENABLE=	ipv6

JPILOT_DESC=		JPilot support
JPILOT_CONFIGURE_ENABLE=	jpilot
JPILOT_LIB_DEPENDS=	libpisock.so:palm/pilot-link
JPILOT_RUN_DEPENDS=	jpilot:palm/jpilot

LDAP_CONFIGURE_ENABLE=	ldap
LDAP_USE=		openldap=yes

MANUAL_DESC=		User manual (many dependencies, including texlive)
MANUAL_CONFIGURE_ON=	--enable-manual --with-manualdir=${DOCSDIR}/manual
MANUAL_CONFIGURE_OFF=	--disable-manual
MANUAL_BUILD_DEPENDS=	docbook-utils>0:textproc/docbook-utils

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext-tools

STARTUP_DESC=		Startup notification support
STARTUP_CONFIGURE_ENABLE=	startup-notification
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

THEMES_DESC=		Additional themes
THEMES_RUN_DEPENDS=	claws-mail-themes>0:x11-themes/claws-mail-themes

.include "Makefile.claws"

post-patch:
	@${REINPLACE_CMD} 's|-dirty||' ${WRKSRC}/version

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} OOo2claws-mail.pl acroread2claws-mail.pl \
		calypso_convert.pl convert_mbox.pl eud2gc.py filter_conv.pl \
		filter_conv_new.pl fix_date.sh gif2xface.pl google_msgid.pl \
		google_search.pl kmail-mailbox2claws-mail.pl kmail2claws-mail.pl \
		kmail2claws-mail_v2.pl multiwebsearch.conf multiwebsearch.pl \
		nautilus2claws-mail.sh outlook2claws-mail.pl tb2claws-mail \
		tbird2claws.py textviewer.pl textviewer.sh \
		thunderbird-filters-convertor.pl uudec uuooffice vcard2xml.py \
		${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	(cd ${WRKSRC} && ${INSTALL_DATA} NEWS README TODO ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/tools/README ${STAGEDIR}${DOCSDIR}/README.tools

.include <bsd.port.mk>
