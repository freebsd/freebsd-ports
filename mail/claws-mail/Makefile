# New ports collection makefile for:	claws-mail
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	claws-mail
PORTVERSION=	2.7.2
CATEGORIES=	mail news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
DISTFILES=	${EXTRACT_ONLY} \
		${THEMEFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A lightweight and very featureful GTK+ based e-mail and news client

LIB_DEPENDS=	etpan:${PORTSDIR}/mail/libetpan
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS=	sylpheed-claws

THEMEVERSION=	20070116
THEMEFILE=	claws-mail-themes-${THEMEVERSION}.tar.gz

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehack pkgconfig gtk20
#USE_AUTOTOOLS=	autoconf:259 libtool:15
GNU_CONFIGURE=	yes
USE_GCC=	3.3+
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

MAN1=		claws-mail.1

CONFIGURE_ARGS=	\
		--with-libiconv-prefix=${LOCALBASE} \
		--with-manualdir=${DOCSDIR}/manual \
		--with-faqdir=${DOCSDIR}/faq \
		--mandir=${PREFIX}/man

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	ALL		"Enable all options."			off \
		ASPELL		"Enable spell checking support."	on \
		CLAMAV		"Enable virus-checking support."	off \
		COMPFACE	"Enable X-Face support."		on \
		DEBUG		"Enable debug support."			off \
		DILLO		"Enable Dillo HTML viewer."		off \
		GNOMEPRINT	"Enable extended print support (GNOME)."	off \
		GPGME		"Enable PGP/GnuPG support using GPGME."	off \
		IPV6		"Enable ipv6 support."			on \
		JPILOT		"Enable JPilot support."		off \
		LDAP		"Enable LDAP support."			off \
		SA_PLUG		"Enable SpamAssassin support."		off \
		SSL		"Enable OpenSSL support."		on \
		THEMES		"Install additional themes."		on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-openssl --with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if ${HAVE_GNOME:Mgnomeprint} != "" || defined(WITH_GNOMEPRINT)
PLIST_SUB+=		GNOMEPRINT=""
USE_GNOME+=		libgnomeprint libgnomeprintui
CONFIGURE_ARGS+=	--enable-gnomeprint
.else
PLIST_SUB+=		GNOMEPRINT="@comment "
CONFIGURE_ARGS+=	--disable-gnomeprint
.endif

.if exists(${LOCALBASE}/include/clamav.h)
WITH_CLAMAV=		yes
.endif

.if defined(WITH_CLAMAV) || defined(WITH_ALL)
CONFIGURE_ARGS+=	--enable-clamav-plugin
PLIST_SUB+=		CLAM_PLUG=""
BUILD_DEPENDS=	   	${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
.else
CONFIGURE_ARGS+=	--disable-clamav-plugin
PLIST_SUB+=		CLAM_PLUG="@comment "
.endif
.if defined(WITH_COMPFACE) || defined(WITH_ALL)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--enable-compface
.else
CONFIGURE_ARGS+=	--disable-compface
.endif
.if defined(WITH_ASPELL) || defined(WITH_ALL)
LIB_DEPENDS+=		pspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--enable-aspell
.else
CONFIGURE_ARGS+=	--disable-aspell
.endif
.if defined(WITH_JPILOT) || defined(WITH_ALL)
LIB_DEPENDS+=		pisock:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif
.if defined(WITH_LDAP) || defined(WITH_ALL)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif
.if defined(WITH_SA_PLUG) || defined(WITH_ALL)
RUN_DEPENDS+=		spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG=""
.else
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG="@comment "
.endif
.if defined(WITH_GPGME) || defined(WITH_ALL)
PLIST_SUB+=		GPGME=""
CONFIGURE_ARGS+=	--enable-pgpmime-plugin --enable-pgpcore-plugin \
			--enable-pgpinline-plugin
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
.else
PLIST_SUB+=		GPGME="@comment "
CONFIGURE_ARGS+=	--disable-pgpmime-plugin --disable-pgpcore-plugin \
			--disable-pgpinline-plugin
.endif
.if defined(WITHOUT_THEMES)
PLIST_SUB+=	THEMES="@comment "
.else
PLIST_SUB+=	THEMES=""
.endif
.if defined(WITH_DEBUG) || defined(WITH_ALL)
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-crash-dialog
STRIP=
.endif
.if defined(WITH_DILLO) || defined(WITH_ALL)
PLIST_SUB+=	DILLO=""
RUN_DEPENDS+=	dillo:${PORTSDIR}/www/dillo
.else
PLIST_SUB+=	DILLO="@comment "
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
.endif

.if defined(WITHOUT_IPV6) || defined(WITH_ALL)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-extract:
.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${WRKSRC}/themes
	@cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${THEMEFILE} ${EXTRACT_AFTER_ARGS}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lresolv||g; s|-lpisock\"|-liconv &|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/tools/README.sylprint ${WRKSRC}/tools/sylprint.pl
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g ; s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/procmime.c
	@${REINPLACE_CMD} -e "s|po intl src|po src| ; s:@CLAWS_GNOME2:#@CLAWS_GNOME2:g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s:-Wno-unused-function::" ${WRKSRC}/src/Makefile.in
	@for f in `${FIND} ${WRKSRC}/tools -type f -print`; do \
		${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" $$f; done
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|src manual faq tools|src tools|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
.for i in NEWS README RELEASE_NOTES TODO tools/README.sylprint
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/tools/README ${DOCSDIR}/README.tools
.endif
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} OOo2claws-mail.pl acroread2claws-mail.pl \
		calypso_convert.pl convert_mbox.pl eud2gc.py filter_conv.pl \
		freshmeat_search.pl gif2xface.pl google_msgid.pl \
		google_search.pl kmail2claws-mail.pl kmail2claws-mail_v2.pl \
		maildir2claws-mail.pl multiwebsearch.conf multiwebsearch.pl \
		nautilus2claws-mail.sh outlook2claws-mail.pl tb2claws-mail \
		textviewer.sh update-po uudec vcard2xml.py \
		${DATADIR}
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/claws-mail.desktop ${PREFIX}/share/applications/
.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${DATADIR}/themes
	@cd ${WRKDIR}/${THEMEFILE:C/.tar.gz//} && ${FIND} . -mindepth 2 -print | \
		${GREP} -vE '(Makefile.*|INSTALL)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DATADIR}/themes/
	@${CHMOD} -R a+r ${DATADIR}/themes
	@${FIND} ${DATADIR}/themes -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${DATADIR}/themes -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylprint.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tools/sylprint.rc ${PREFIX}/etc/sylprint.rc.example
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/claws-mail*.png ${PREFIX}/share/pixmaps/

.include <bsd.port.post.mk>
