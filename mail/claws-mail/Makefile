# New ports collection makefile for:	sylpheed-claws
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	sylpheed-claws
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	mail news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
DISTNAME=	sylpheed-${PORTVERSION}claws
DISTFILES=	${EXTRACT_ONLY} \
		${THEMEFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A lightweight and very featureful GTK+ based e-mail and news client

THEMEVERSION=	20031130
THEMEFILE=	sylpheed-iconset-${THEMEVERSION}.tar.gz

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes

MAN1=		sylpheed-claws.1

.if !defined(WITHOUT_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS=		--enable-openssl --with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--program-suffix="-claws" --enable-ipv6

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

.if defined(WITH_PIXBUF) || defined(WITH_ALL)
USE_GNOME+=		gdkpixbuf
CONFIGURE_ARGS+=	--disable-imlib
.else
USE_GNOME+=		imlib
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif
.if defined(WITH_GPGME) || defined(WITH_ALL)
LIB_DEPENDS+=		gpgme.9:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--enable-gpgme
.endif
.if defined(WITH_COMPFACE) || defined(WITH_ALL)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
.else
CONFIGURE_ARGS+=	--disable-compface
.endif
.if defined(WITH_JCONV) || defined(WITH_ALL)
LIB_DEPENDS+=		jconv.0:${PORTSDIR}/japanese/libjconv
.else
CONFIGURE_ARGS+=	--disable-jconv
.endif
.if defined(WITH_ASPELL) || defined(WITH_ALL)
LIB_DEPENDS+=		pspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--enable-aspell
.endif
.if defined(WITH_JPILOT) || defined(WITH_ALL)
LIB_DEPENDS+=		pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=		jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=	--enable-jpilot
.endif
.if defined(WITH_LDAP) || defined(WITH_ALL)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20-client
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ENV+=		PTHREAD_LIBS=${PTHREAD_LIBS:S/"//g}
.endif
.if defined(WITH_SA_PLUG) || defined(WITH_ALL)
RUN_DEPENDS+=		spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin-plugin
PLIST_SUB+=		SA_PLUG=""
.else
PLIST_SUB+=		SA_PLUG="@comment "
.endif
.if defined(WITHOUT_THEMES)
PLIST_SUB+=	THEMES="@comment "
.else
PLIST_SUB+=	THEMES=""
.endif
.if defined(WITHOUT_IMAGE)
PLIST_SUB+= IMAGE="@comment "
CONFIGURE_ARGS+=	--disable-image-viewer-plugin
.else
PLIST_SUB+= IMAGE=""
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_ALL       Enable all options below"
	@${ECHO} ""
	@${ECHO} "      WITH_PIXBUF    Enable GDK Pixbuf support"
	@${ECHO} "      WITH_GPGME     Enable GnuPG support using GPGME"
	@${ECHO} "      WITH_COMPFACE  Enable compface (X-Face) support"
	@${ECHO} "      WITH_JCONV     Enable enhanced charset conversion"
	@${ECHO} "      WITH_ASPELL    Enable spell-checking support"
	@${ECHO} "      WITH_JPILOT    Enable JPilot support"
	@${ECHO} "      WITH_LDAP      Enable LDAP access support"
	@${ECHO} "      WITH_SA_PLUG   Build Spamassassin plugin"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL    Disable OpenSSL support"
	@${ECHO} "      WITHOUT_IMAGE  Disable internal image viewer"
	@${ECHO} "      WITHOUT_THEMES Don't install additional themes"
	@${ECHO} ""

post-extract:
.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${WRKSRC}/themes
	@cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${THEMEFILE} ${EXTRACT_AFTER_ARGS}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/tools/README.sylprint ${WRKSRC}/tools/sylprint.pl
	@${REINPLACE_CMD} -e "s|po intl src|po src|" ${WRKSRC}/Makefile.in
	@for f in ${WRKSRC}/tools/*; do \
		${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" $$f; done
	#@${LN} -s ${WRKSRC}/po/sylpheed.pot ${WRKSRC}/po/${PORTNAME}.pot
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|src manual faq tools|src tools|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
.for i in NEWS README README.jp README.claws RELEASE_NOTES.claws TODO TODO.jp tools/README.sylprint
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/tools/README ${DOCSDIR}/README.tools
.endif
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} OOo2sylpheed.pl calypso_convert.pl \
		convert_mbox.pl eud2gc.py filter_conv.pl freshmeat_search.pl \
		gif2xface.pl google_msgid.pl google_search.pl \
		gpg-sign-syl kmail2sylpheed.pl kmail2sylpheed_v2.pl \
		launch_firebird maildir2sylpheed.pl multiwebsearch.conf \
		multiwebsearch.pl newscache_clean.pl outlook2sylpheed.pl \
		tb2sylpheed update-po uudec vcard2xml.py ${DATADIR}
.if !defined(WITHOUT_THEMES)
	@${MKDIR} ${DATADIR}/themes
	@cd ${WRKDIR}/${THEMEFILE:C/.tar.gz//} && ${FIND} . -print | \
		${GREP} -vE '(xvpics|.directory)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DATADIR}/themes/
	@${CHMOD} -R a+r ${DATADIR}/themes
	@${FIND} ${DATADIR}/themes -type d -print0 | xargs -0 ${CHMOD} a+x
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylpheed-switcher ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylprint.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tools/sylprint.rc ${PREFIX}/etc/sylprint.rc.example
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${PREFIX}/share/pixmaps/sylpheed-claws.png

.include <bsd.port.post.mk>
