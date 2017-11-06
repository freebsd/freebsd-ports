# $FreeBSD$

PORTNAME?=	alpine
PORTVERSION=	2.21
PORTREVISION?=	1
CATEGORIES?=	mail news ipv6
MASTER_SITES=	http://alpine.freeiz.com/alpine/release/src/
DIST_SUBDIR=	alpine-${PORTVERSION}

MAINTAINER=	mbeis@xs4all.nl
COMMENT?=	Mail and news client descended from Pine

LICENSE=	APACHE20

USES+=			ssl libtool ncurses tar:xz gettext-runtime
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS+=	--with-debug-level=2 \
			--enable-background-post \
			--without-krb5 \
			--without-tcl \
			--with-system-pinerc=${PREFIX}/etc/alpine.conf \
			--with-system-fixed-pinerc=${PREFIX}/etc/alpine.conf.fixed \
			--with-password-prog=/usr/bin/passwd \
			--with-system-mail-directory=/var/mail \
			--with-ssl-dir=${OPENSSLDIR} \
			--with-ssl-include-dir=${OPENSSLINC} \
			--with-ssl-lib-dir=${OPENSSLLIB} \
			--with-ssl-certs-dir=${OPENSSLDIR}/certs
MAKE_ARGS+=		CC="${CC}" CXX="${CXX}" GCCCFLAGS="${CFLAGS}"

OPTIONS_DEFINE=		ASPELL CONS25 DOCS IPV6 LDAP MAILDIR MOUSE PASSFILE NLS THREADS
OPTIONS_DEFAULT=	ASPELL MOUSE THREADS
.if defined(PICO_ALPINE_SLAVE)
OPTIONS_EXCLUDE=	CONS25 IPV6 LDAP MAILDIR PASSFILE
.endif

CONS25_DESC=	Add a patch to support color for default console
MAILDIR_DESC=	Add a patch for maildir support
PASSFILE_DESC=	Support for a stored password file

# Option ASPELL
ASPELL_CONFIGURE_ON=		--with-interactive-spellcheck=${LOCALBASE}/bin/aspell
ASPELL_CONFIGURE_OFF=		--with-simple-spellcheck
ASPELL_BUILD_DEPENDS=		aspell:textproc/aspell
ASPELL_RUN_DEPENDS=		aspell:textproc/aspell

# Option CONS25
CONS25_EXTRA_PATCHES=		${FILESDIR}/cons25-alpine_keymenu.c

# Option IPV6
IPV6_CONFIGURE_WITH=		ipv6

# Option LDAP
LDAP_USE=			openldap=yes
LDAP_CONFIGURE_WITH=		ldap
LDAP_CONFIGURE_ON=		--with-ldap-dir=${LOCALBASE}

# Option MAILDIR
MAILDIR_PATCH_SITES=		http://alpine.freeiz.com/alpine/patches/alpine-${PORTVERSION}/
MAILDIR_PATCHFILES+=		maildir.patch.gz:-p1

# Option MOUSE
MOUSE_CONFIGURE_ENABLE=		mouse

# Option NLS
NLS_CONFIGURE_ENABLE=		nls

# Option PASSFILE
PASSFILE_CONFIGURE_WITH=	passfile
PASSFILE_CONFIGURE_ON=		--with-passfile=.alpine.pwd

# Option THREADS
THREADS_CONFIGURE_WITH=		pthread

.if !defined(PICO_ALPINE_SLAVE)
PORTDOCSbase=		LICENSE NOTICE README
PORTDOCSdoc=		brochure.txt
PORTDOCShtml=		tech-notes/background.html tech-notes/cmd-line.html \
			tech-notes/config-notes.html tech-notes/config.html \
			tech-notes/index.html tech-notes/installation.html \
			tech-notes/introduction.html tech-notes/low-level.html \
			tech-notes/tech-notes.txt
PORTDOCS=		${PORTDOCSbase} ${PORTDOCSdoc} ${PORTDOCShtml}

post-patch:
	@${CP} ${WRKSRC}/imap/Makefile ${WRKSRC}/imap/Makefile.presed
	@${SED}	-e "s#^\(all:.*\) bundled\$$#\1#" \
	    ${WRKSRC}/imap/Makefile.presed > ${WRKSRC}/imap/Makefile
	@${CP} ${WRKSRC}/pico/Makefile.in ${WRKSRC}/pico/Makefile.in.presed
	@${SED} -e "s#^bin_PROGRAMS = pico.*#bin_PROGRAMS =#" \
	    -e "s#\$$(pico_SOURCES) \$$(pilot_SOURCES)##" \
	    ${WRKSRC}/pico/Makefile.in.presed > ${WRKSRC}/pico/Makefile.in
	@${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED}	-e "s#doc/man1/pico.1 doc/man1/pilot.1 ##" \
	    ${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/imap/src/osdep/unix/Makefile \
	    ${WRKSRC}/imap/src/osdep/unix/Makefile.presed
	@${SED} -e "s#^LOCKPGM=.*#LOCKPGM= ${PREFIX}/libexec/mlock#" \
	    ${WRKSRC}/imap/src/osdep/unix/Makefile.presed \
	    > ${WRKSRC}/imap/src/osdep/unix/Makefile
	@for i in ${WRKSRC}/README ${WRKSRC}/doc/man1/alpine.1 \
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

post-install-DOCS-on:
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
.endif # !defined(PICO_ALPINE_SLAVE)

.include <bsd.port.mk>
