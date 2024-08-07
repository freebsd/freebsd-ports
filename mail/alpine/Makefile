PORTNAME?=	alpine
DISTVERSION=	2.26
PORTREVISION=	2
CATEGORIES?=	mail news
MASTER_SITES=	https://repo.or.cz/alpine.git/snapshot/${GIT_COMMIT}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	mbeis@xs4all.nl
COMMENT?=	Mail and news client descended from Pine
WWW?=		https://alpineapp.email/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe gettext-runtime libtool ncurses ssl

CPE_VENDOR=	alpine_project

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-background-post \
			--with-debug-level=2 \
			--with-password-prog=/usr/bin/passwd \
			--with-ssl-certs-dir=${OPENSSLDIR}/certs \
			--with-ssl-dir=${OPENSSLDIR} \
			--with-ssl-include-dir=${OPENSSLINC} \
			--with-ssl-lib-dir=${OPENSSLLIB} \
			--with-system-fixed-pinerc=${PREFIX}/etc/alpine.conf.fixed \
			--with-system-mail-directory=/var/mail \
			--with-system-pinerc=${PREFIX}/etc/alpine.conf \
			--without-krb5 \
			--without-tcl
MAKE_ARGS+=		CC="${CC}" \
			CXX="${CXX}" \
			GCCCFLAGS="${CFLAGS}"
MAKE_JOBS_UNSAFE=	yes
# When you update please double check that the commit corresponds to
# the actual version you've set in PORTVERSION.
GIT_COMMIT=		9726c098a739edfdca6218bc5dee104c310957e9
GIT_COMMIT_SHORT=	${GIT_COMMIT:C/^(.......).*/\1/}
WRKSRC=			${WRKDIR}/alpine-${GIT_COMMIT_SHORT}

OPTIONS_DEFINE=		ASPELL CONS25 DOCS IPV6 LDAP MAILDIR MOUSE NLS NTLM \
			PASSFILE THREADS
OPTIONS_DEFAULT=	ASPELL MOUSE THREADS
.if defined(PICO_ALPINE_SLAVE)
OPTIONS_EXCLUDE=	CONS25 IPV6 LDAP PASSFILE
.endif

CONS25_DESC=	Add a patch to support color for default console
MAILDIR_DESC=	Add a patch to support maildir
NTLM_DESC=	Support for Windows NT Lan Manager authentication
PASSFILE_DESC=	Support for a stored password file

# Option ASPELL
ASPELL_BUILD_DEPENDS=	aspell:textproc/aspell
ASPELL_RUN_DEPENDS=	aspell:textproc/aspell
ASPELL_CONFIGURE_ON=	--with-interactive-spellcheck=${LOCALBASE}/bin/aspell
ASPELL_CONFIGURE_OFF=	--with-simple-spellcheck

# Option CONS25
CONS25_EXTRA_PATCHES=	${FILESDIR}/cons25-alpine_keymenu.c

# Option IPV6
IPV6_CONFIGURE_WITH=	ipv6

# Option LDAP
LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap
LDAP_CFLAGS=		-I${LOCALBASE}/include
LDAP_LDFLAGS=		-L${LOCALBASE}/lib

# Option MAILDIR
MAILDIR_PATCH_SITES=	https://alpineapp.email/alpine/patches/alpine-2.26/
MAILDIR_PATCHFILES+=	maildir.patch.gz:-p1

# Option MOUSE
MOUSE_CONFIGURE_ENABLE=	mouse

# Option NLS
NLS_CONFIGURE_ENABLE=	nls

# Option NTLM
NTLM_LIB_DEPENDS=	libntlm.so:security/libntlm
NTLM_CONFIGURE_WITH=	ntlm

# Option PASSFILE
PASSFILE_CONFIGURE_WITH=	passfile
PASSFILE_CONFIGURE_ON=		--with-passfile=.alpine.pwd

# Option THREADS
THREADS_CONFIGURE_WITH=	pthread

.if !defined(PICO_ALPINE_SLAVE)
PORTDOCSbase=	LICENSE NOTICE README
PORTDOCSdoc=	brochure.txt
PORTDOCShtml=	tech-notes/background.html tech-notes/cmd-line.html \
		tech-notes/config-notes.html tech-notes/config.html \
		tech-notes/index.html tech-notes/installation.html \
		tech-notes/introduction.html tech-notes/low-level.html \
		tech-notes/tech-notes.txt
PORTDOCS=	${PORTDOCSbase} ${PORTDOCSdoc} ${PORTDOCShtml}

post-patch:
	@${REINPLACE_CMD} -e "s#^\(all:.*\) bundled\$$#\1#" ${WRKSRC}/imap/Makefile
	@${REINPLACE_CMD} -e "s#^bin_PROGRAMS = pico.*#bin_PROGRAMS =#" \
	    -e "s#\$$(pico_SOURCES) \$$(pilot_SOURCES)##" ${WRKSRC}/pico/Makefile.in
	@${REINPLACE_CMD} -e "s#doc/man1/pico.1 doc/man1/pilot.1 ##" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#^LOCKPGM=.*#LOCKPGM= ${PREFIX}/libexec/mlock#" \
	    ${WRKSRC}/imap/src/osdep/unix/Makefile
	@${REINPLACE_CMD} -e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
	    -e "s:/usr/local/pine.conf:${PREFIX}/etc/pine.conf:g" \
	    -e "s:pine\.conf:alpine.conf:g" \
	    -e "s:/usr/local:${PREFIX}:g" \
	    -e "s:@@PREFIX@@:${PREFIX}:g" \
	    ${WRKSRC}/README ${WRKSRC}/doc/man1/alpine.1 \
	    ${WRKSRC}/doc/*.txt \
	    ${WRKSRC}/doc/tech-notes/*.txt \
	    ${WRKSRC}/doc/tech-notes/*.html \
	    ${WRKSRC}/pith/pine.hlp

post-install:
	${STAGEDIR}${PREFIX}/bin/alpine -conf > ${STAGEDIR}${PREFIX}/etc/alpine.conf.sample

post-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/tech-notes
.for f in ${PORTDOCSbase}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCSdoc}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}/tech-notes
.endfor
.endif # !defined(PICO_ALPINE_SLAVE)

.include <bsd.port.mk>
