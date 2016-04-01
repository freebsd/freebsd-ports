# $FreeBSD$

PORTNAME?=	alpine
PORTVERSION=	2.20
PORTREVISION?=	1
CATEGORIES?=	mail news ipv6
MASTER_SITES=	http://patches.freeiz.com/alpine/release/src/
DIST_SUBDIR=	alpine-${PORTVERSION}

MAINTAINER=	mbeis@xs4all.nl
COMMENT?=	Mail and news client descended from Pine

LICENSE=	APACHE20

OPTIONS_DEFINE=		DOCS SSL THREADS MOUSE NLS ISPELL NOSPELL
OPTIONS_DEFAULT+=	DOCS SSL THREADS MOUSE
SSL_DESC=	Build with SSL (installs: security/openssl if pre 10.x)
MOUSE_DESC=	Enable mouse support for xterm
ISPELL_DESC=	Use ispell instead of aspell as default speller
NOSPELL_DESC=	Use no default speller (overrides both)

.if !defined(PICO_ALPINE_SLAVE)

OPTIONS_DEFINE+=	PICO IPV6 LDAP PASSFILE CONS25 MAILDIR SSL
OPTIONS_DEFAULT+=	PICO SSL
PICO_DESC=	Build and install pico, the default editor
PASSFILE_DESC=	Support for a stored password file (DANGEROUS)
CONS25_DESC=	Add a patch to support color for default console
MAILDIR_DESC=	Add a patch for maildir support
.endif

USES=		libtool ncurses tar:xz

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes

.if !defined(PICO_ALPINE_SLAVE)

PORTDOCSbase=	LICENSE NOTICE README
PORTDOCSdoc=	brochure.txt
PORTDOCShtml=	tech-notes/background.html tech-notes/cmd-line.html \
		tech-notes/config-notes.html tech-notes/config.html \
		tech-notes/index.html tech-notes/installation.html \
		tech-notes/introduction.html tech-notes/low-level.html \
		tech-notes/tech-notes.txt
PORTDOCS=	${PORTDOCSbase} ${PORTDOCSdoc} ${PORTDOCShtml}

CONFIGURE_ARGS+=--with-system-pinerc=${PREFIX}/etc/alpine.conf \
		--with-system-fixed-pinerc=${PREFIX}/etc/alpine.conf.fixed \
		--with-password-prog=/usr/bin/passwd \
		--with-system-mail-directory=/var/mail

.endif
CONFIGURE_ARGS+=--with-debug-level=2 \
		--enable-background-post --without-krb5 --without-tcl

MAKE_ARGS+=	CC="${CC}" CXX="${CXX}" GCCCFLAGS="${CFLAGS}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.if  ${OSVERSION} < 1000000
# OpenSSL is pre v1.0 in FBSD9.x so the ports version needs to be used
WITH_OPENSSL_PORT=	yes
.endif

CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLDIR} \
			--with-ssl-include-dir=${OPENSSLINC} \
			--with-ssl-lib-dir=${OPENSSLLIB} \
			--with-ssl-certs-dir=${OPENSSLDIR}/certs
.else
CONFIGURE_ARGS+=	--without-ssl
USE_OPENSSL=		no
.endif

.include <bsd.port.pre.mk>

THREADS_CONFIGURE_WITH=	pthread
MOUSE_CONFIGURE_ENABLE=	mouse
NLS_CONFIGURE_ENABLE=	nls
IPV6_CONFIGURE_WITH=	ipv6

.if ! ${PORT_OPTIONS:MNOSPELL}
.if ! ${PORT_OPTIONS:MISPELL}
CONFIGURE_ARGS+=--with-interactive-spellcheck=${LOCALBASE}/bin/aspell
BUILD_DEPENDS+=	aspell:textproc/aspell
RUN_DEPENDS+=	aspell:textproc/aspell
.else
CONFIGURE_ARGS+=	--with-interactive-spellcheck=${LOCALBASE}/bin/ispell
BUILD_DEPENDS+=	ispell:textproc/aspell-ispell
RUN_DEPENDS+=	ispell:textproc/aspell-ispell
.endif
.else
CONFIGURE_ARGS+=--without-simple-spellcheck --without-interactive-spellcheck
.endif

.if !defined(PICO_ALPINE_SLAVE)
.if ${PORT_OPTIONS:MPICO}
RUN_DEPENDS+=	pico:editors/pico-alpine
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MPASSFILE}
ALPINE_PASSFILE?=	.alpine.pwd
CONFIGURE_ARGS+=	--with-passfile=.alpine.pwd
.endif

.if ${PORT_OPTIONS:MMAILDIR}
PATCH_SITES=		http://patches.freeiz.com/alpine/patches/alpine-${PORTVERSION}/
PATCHFILES+=		maildir.patch.gz
PATCH_DIST_ARGS+=	-E --quiet -d ${PATCH_WRKSRC} -p1
.endif

.if ${PORT_OPTIONS:MCONS25}
EXTRA_PATCHES=		${FILESDIR}/cons25-alpine_keymenu.c
.endif

pre-patch:
	@${CHMOD} -R u+w ${WRKSRC}

post-patch:
	@${CP} ${WRKSRC}/imap/Makefile ${WRKSRC}/imap/Makefile.presed
	@${SED}	-e "s#^\(all:.*\) bundled\$$#\1#" \
	    ${WRKSRC}/imap/Makefile.presed > ${WRKSRC}/imap/Makefile
	@${CP} ${WRKSRC}/pico/Makefile.in ${WRKSRC}/pico/Makefile.in.presed
	@${SED} -e "s#^bin_PROGRAMS = pico.*#bin_PROGRAMS =#" \
	    -e "s#\$$(pico_SOURCES) \$$(pilot_SOURCES)##" \
	    ${WRKSRC}/pico/Makefile.in.presed > ${WRKSRC}/pico/Makefile.in
	@${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED}	-e "s#doc/pico.1 doc/pilot.1 ##" \
	    ${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/imap/src/osdep/unix/Makefile \
	    ${WRKSRC}/imap/src/osdep/unix/Makefile.presed
	@${SED} -e "s#^LOCKPGM=.*#LOCKPGM= ${PREFIX}/libexec/mlock#" \
	    ${WRKSRC}/imap/src/osdep/unix/Makefile.presed \
	    > ${WRKSRC}/imap/src/osdep/unix/Makefile
	@for i in ${WRKSRC}/README ${WRKSRC}/doc/alpine.1 \
	    ${WRKSRC}/doc/*.txt \
	    ${WRKSRC}/doc/tech-notes/*.txt \
	    ${WRKSRC}/doc/tech-notes/*.html \
	    ${WRKSRC}/pith/pine.hlp ; do \
		${CP} $$i $$i.presed ; \
		${SED} -e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
		    -e "s:/usr/local/pine.conf:${PREFIX}/etc/pine.conf:g" \
		    -e "s:pine\.conf:alpine.conf:g" \
		    -e "s:/usr/local:${PREFIX}:g" \
		    -e "s:@@PREFIX@@:${PREFIX}:g" \
		    $$i.presed > $$i ; \
	done

post-install:
	${STAGEDIR}${PREFIX}/bin/alpine -conf > ${STAGEDIR}${PREFIX}/etc/alpine.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/tech-notes
.for f in ${PORTDOCSbase}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCSdoc}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}/tech-notes
.endfor
.endif

#	PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
#	@${CAT} ${PKGMESSAGE}

.endif	# !defined(PICO_ALPINE_SLAVE)

.include <bsd.port.post.mk>
