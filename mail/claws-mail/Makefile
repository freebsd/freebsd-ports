PORTNAME=	claws-mail
CATEGORIES=	mail news

COMMENT=	Lightweight and featureful GTK based e-mail and news client
WWW=		https://www.claws-mail.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libetpan.so:mail/libetpan \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		mime-support>0:misc/mime-support

USES=		cpe desktop-file-utils pathfix perl5 python shebangfix xorg
USE_GNOME=	librsvg2
USE_XORG=	ice sm
SHEBANG_FILES=	tools/*.pl tools/*.py tools/tb2claws-mail

CPPFLAGS+=	-DGDK_DISABLE_DEPRECATION_WARNINGS

OPTIONS_DEFINE=		COMPFACE DEBUG DOCS ENCHANT IPV6 LDAP NLS STARTUP \
			THEMES
OPTIONS_DEFAULT=	COMPFACE ENCHANT GTK2 STARTUP THEMES
OPTIONS_RADIO=		BRANCH
OPTIONS_RADIO_BRANCH=	GTK2 GTK3
OPTIONS_SUB=		yes

COMPFACE_DESC=	X-Face support
ENCHANT_DESC=	Spell checking support
GTK2_DESC=	Build GTK2+ release
GTK3_DESC=	Build GTK3+ release
STARTUP_DESC=	Startup notification support
THEMES_DESC=	Additional themes

COMPFACE_LIB_DEPENDS=		libcompface.so:mail/faces
COMPFACE_CONFIGURE_ENABLE=	compface

DEBUG_CONFIGURE_ON=	--enable-maintainer-mode

ENCHANT_LIB_DEPENDS=		libenchant.so:textproc/enchant
ENCHANT_CONFIGURE_ENABLE=	enchant

IPV6_CONFIGURE_ENABLE=	ipv6

LDAP_USES=		ldap
LDAP_CONFIGURE_ENABLE=	ldap

STARTUP_LIB_DEPENDS=		libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification

THEMES_RUN_DEPENDS=	claws-mail-themes>0:x11-themes/claws-mail-themes

.include <bsd.port.options.mk>
MASTER_OPTIONS=	${PORT_OPTIONS}
.include "Makefile.claws"

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	${WRKSRC}/src/common/ssl.c

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} acroread2claws-mail.pl \
		calypso_convert.pl claws-mail-compose-insert-files.pl \
		cm-reparent.pl convert_mbox.pl csv2addressbook.pl ddg_search.pl \
		eud2gc.py filter_conv.pl filter_conv_new.pl fix_date.sh \
		gif2xface.pl google_msgid.pl kmail-mailbox2claws-mail.pl \
		kmail2claws-mail.pl kmail2claws-mail_v2.pl mairix.sh \
		mew2claws-mail.pl multiwebsearch.conf multiwebsearch.pl \
		nautilus2claws-mail.sh outlook2claws-mail.pl popfile-link.sh \
		tb2claws-mail tbird2claws.py textviewer.pl textviewer.sh \
		thunderbird-filters-convertor.pl update-po uudec uuooffice \
		vcard2xml.py \
		${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	(cd ${WRKSRC} && ${INSTALL_DATA} NEWS README ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/tools/README ${STAGEDIR}${DOCSDIR}/README.tools

.include <bsd.port.mk>
