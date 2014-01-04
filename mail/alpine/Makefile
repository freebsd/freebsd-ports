# $FreeBSD$

PORTNAME?=	alpine
PORTVERSION=	2.00
PORTREVISION?=	4
CATEGORIES?=	mail news ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
DIST_SUBDIR=	alpine-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Mail and news client descended from Pine

OPTIONS_DEFINE+=	THREADS MOUSE NLS ISPELL NOSPELL
OPTIONS_DEFAULT+=	THREADS MOUSE
MOUSE_DESC=	Enable mouse support for xterm
ISPELL_DESC=	Use ispell instead of aspell as default speller
NOSPELL_DESC=	Use no default speller (overrides both)
.if !defined(PICO_ALPINE_SLAVE)
OPTIONS_DEFINE+=	PICO IPV6 LDAP PASSFILE CONS25 QUOTA MAILDIR SSL
OPTIONS_DEFAULT+=	PICO SSL
PICO_DESC=	Build and install pico, the default editor
PASSFILE_DESC=	Support for a stored password file (DANGEROUS)
CONS25_DESC=	Add a patch to support color for default console
QUOTA_DESC=	Add a patch for disk quota checking on IMAP
MAILDIR_DESC=	Add a patch for maildir support
.endif

USE_BZIP2=	yes

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes

.if !defined(PICO_ALPINE_SLAVE)
CONFIGURE_ARGS+=--with-system-pinerc=${PREFIX}/etc/alpine.conf \
		--with-system-fixed-pinerc=${PREFIX}/etc/alpine.conf.fixed \
		--with-password-prog=/usr/bin/passwd \
		--with-system-mail-directory=/var/mail \
		--enable-background-post --without-krb5 --without-tcl
.endif
CONFIGURE_ARGS+=--with-debug-level=2

MAKE_ARGS+=	CC="${CC}" CXX="${CXX}" GCCCFLAGS="${CFLAGS}"

USE_OPENSSL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--with-pthread
.else
CONFIGURE_ARGS+=	--without-pthread
.endif

.if ${PORT_OPTIONS:MMOUSE}
CONFIGURE_ARGS+=	--enable-mouse
.else
CONFIGURE_ARGS+=	--disable-mouse
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ! ${PORT_OPTIONS:MNOSPELL}
.if ! ${PORT_OPTIONS:MISPELL}
CONFIGURE_ARGS+=--with-interactive-spellcheck=${LOCALBASE}/bin/aspell
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=	--with-interactive-spellcheck=${LOCALBASE}/bin/ispell
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
.else
CONFIGURE_ARGS+=--without-simple-spellcheck --without-interactive-spellcheck
.endif

.if !defined(PICO_ALPINE_SLAVE)
.if ${PORT_OPTIONS:MPICO}
RUN_DEPENDS+=	pico:${PORTSDIR}/editors/pico-alpine
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap --with-ldap-dir=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MPASSFILE}
ALPINE_PASSFILE?=	.alpine.pwd
CONFIGURE_ARGS+=	--with-passfile=.alpine.pwd
.endif

.if ${PORT_OPTIONS:MCONS25}
EXTRA_PATCHES=	${FILESDIR}/cons25-alpine_keymenu.c
.endif

.if ${PORT_OPTIONS:MQUOTA} || ${PORT_OPTIONS:MMAILDIR}
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	dougb/alpine-${PORTVERSION}/
PATCH_DIST_ARGS+=	-E --quiet -d ${PATCH_WRKSRC} -p1
.endif

.if ${PORT_OPTIONS:MQUOTA}
PATCHFILES+=	quota.patch.gz
.endif

.if ${PORT_OPTIONS:MMAILDIR}
PATCHFILES+=	maildir.patch.gz
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLDIR} \
			--with-ssl-include-dir=${OPENSSLINC} \
			--with-ssl-lib-dir=${OPENSSLLIB} \
			--with-ssl-certs-dir=${OPENSSLDIR}/certs
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

MAN1=		alpine.1 rpdump.1 rpload.1

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
	    ${WRKSRC}/doc/tech-notes.txt ${WRKSRC}/doc/tech-notes/*.html \
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
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR} \
	    ${DOCSDIR}/tech-notes
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html ${DOCSDIR}/tech-notes
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${CAT} ${PKGMESSAGE}
.endif	# !defined(PICO_ALPINE_SLAVE)

.include <bsd.port.post.mk>
