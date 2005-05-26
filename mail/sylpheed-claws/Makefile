# New ports collection makefile for:	sylpheed-claws
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	sylpheed-claws
PORTVERSION=	1.9.11
#PORTREVISION=	1
CATEGORIES=	mail news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
DISTFILES=	${EXTRACT_ONLY} \
		${THEMEFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A lightweight and very featureful GTK+ based e-mail and news client

THEMEVERSION=	20040929
THEMEFILE=	sylpheed-iconset-${THEMEVERSION}.tar.gz

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack pkgconfig gtk20
USE_REINPLACE=	yes
WANT_GNOME=	yes

MAN1=		sylpheed-claws.1

CONFIGURE_ARGS=	--program-suffix="-claws" --enable-ipv6 \
		--with-libiconv-prefix=${LOCALBASE}

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(NOPORTDOCS)
EXTRA_PATCHES=		${FILESDIR}/extra-doc:Makefile.in
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-openssl --with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
.if defined(OPENSSLVER)
MYSSLVER=${OPENSSLVER}
.else
MYSSLVER!=openssl version | cut -d ' ' -f 2
.endif
SSLTEST!=test ${MYSSLVER} \< 0.9.7 && ${ECHO_CMD} bad || ${TRUE}
. if ${SSLTEST} == "bad"
IGNORE=You need at least OpenSSL v0.9.7
. endif
.endif

.if ${HAVE_GNOME:Mgnomehier} != ""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if exists(${LOCALBASE}/include/clamav.h)
WITH_CLAMAV=		yes
.endif

.if defined(WITH_CLAMAV) || defined(WITH_ALL)
CONFIGURE_ARGS+=	--enable-clamav
PLIST_SUB+=		CLAM_PLUG=""
BUILD_DEPENDS=	   	${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
.else
CONFIGURE_ARGS+=	--disable-clamav
PLIST_SUB+=		CLAM_PLUG="@comment "
.endif
.if defined(WITH_COMPFACE) || defined(WITH_ALL)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--enable-compface
.else
CONFIGURE_ARGS+=	--disable-compface
.endif
.if defined(WITH_JCONV) || defined(WITH_ALL)
CONFIGURE_ARGS+=	--enable-jconv
LIB_DEPENDS+=		jconv.0:${PORTSDIR}/japanese/libjconv
.else
CONFIGURE_ARGS+=	--disable-jconv
.endif
.if defined(WITH_ASPELL) || defined(WITH_ALL)
LIB_DEPENDS+=		pspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--enable-aspell
.else
CONFIGURE_ARGS+=	--disable-aspell
.endif
.if defined(WITH_JPILOT) || defined(WITH_ALL)
LIB_DEPENDS+=		pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif
.if defined(WITH_LDAP) || defined(WITH_ALL)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
.else
CONFIGURE_ARGS+=	--enable-ldap
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
CONFIGURE_ARGS+=	--enable-pgpmime-plugin
LIB_DEPENDS+=		gpgme03.9:${PORTSDIR}/security/gpgme03
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
.else
PLIST_SUB+=		GPGME="@comment "
CONFIGURE_ARGS+=	--disable-pgpmime-plugin
.endif
.if defined(WITHOUT_THEMES)
PLIST_SUB+=	THEMES="@comment "
.else
PLIST_SUB+=	THEMES=""
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_ALL       Enable all options below"
	@${ECHO} ""
	@${ECHO} "      WITH_COMPFACE  Enable compface (X-Face) support"
	@${ECHO} "      WITH_GPGME     Build the pgpmime plugin"
	@${ECHO} "      WITH_JCONV     Enable enhanced charset conversion"
	@${ECHO} "      WITH_ASPELL    Enable spell-checking support"
	@${ECHO} "      WITH_JPILOT    Enable JPilot support"
	@${ECHO} "      WITH_LDAP      Enable LDAP access support"
	@${ECHO} "      WITH_SA_PLUG   Build Spamassassin plugin"
	@${ECHO} "      WITH_CLAMAV    Build Clamav antivirus plugin"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL    Disable OpenSSL support"
	@${ECHO} "      WITHOUT_THEMES Don't install additional themes"
	@${ECHO} ""

post-extract:
.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${WRKSRC}/themes
	@cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${THEMEFILE} ${EXTRACT_AFTER_ARGS}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lresolv||g; s|-lpisock\"|-liconv &|g ;\
		s|gpgme-config|gpgme03-config|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/tools/README.sylprint ${WRKSRC}/tools/sylprint.pl
	@${REINPLACE_CMD} -e "s|po intl src|po src| ; s:@SYLPHEED_GNOME:#@SYLPHEED_GNOME:g" ${WRKSRC}/Makefile.in
	@for f in `${FIND} ${WRKSRC}/tools -type f -print`; do \
		${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" $$f; done
#	@${LN} -s ${WRKSRC}/po/sylpheed.pot ${WRKSRC}/po/${PORTNAME}.pot
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|src manual faq tools|src tools|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
.for i in NEWS README README.claws RELEASE_NOTES.claws TODO tools/README.sylprint
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/tools/README ${DOCSDIR}/README.tools
.endif
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} OOo2sylpheed.pl acroread2sylpheed.pl \
		calypso_convert.pl convert_mbox.pl eud2gc.py filter_conv.pl \
		freshmeat_search.pl gif2xface.pl google_msgid.pl \
		google_search.pl gpg-sign-syl kmail2sylpheed.pl \
		kmail2sylpheed_v2.pl maildir2sylpheed.pl multiwebsearch.conf \
		multiwebsearch.pl nautilus2sylpheed.sh outlook2sylpheed.pl \
		tb2sylpheed textviewer.sh update-po uudec vcard2xml.py \
		${DATADIR}

.if ${HAVE_GNOME:Mgnomehier} != ""
	@${MKDIR} ${PREFIX}/share/gnome/applications
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.desktop ${PREFIX}/share/gnome/applications/sylpheed-claws.desktop
.endif

.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${DATADIR}/themes
	@cd ${WRKDIR}/${THEMEFILE:C/.tar.gz//} && ${FIND} . -print | \
		${GREP} -vE '(xvpics|.directory)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DATADIR}/themes/
	@${CHMOD} -R a+r ${DATADIR}/themes
	@${FIND} ${DATADIR}/themes -type d -print0 | ${XARGS} -0 ${CHMOD} a+x
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylpheed-switcher ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylprint.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tools/sylprint.rc ${PREFIX}/etc/sylprint.rc.example
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${PREFIX}/share/pixmaps/sylpheed-claws.png

.include <bsd.port.post.mk>
