# New ports collection makefile for:	postfix-current
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	postfix
PORTVERSION=	1.1.13
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/ \
		ftp://ftp.aet.tu-cottbus.de/pub/postfix_tls/%SUBDIR%/ \
		ftp://ftp.tux.org/pub/net/postfix/official/ \
		ftp://ftp.utoronto.ca/mirror/packages/postfix/official/ \
		ftp://ftp.samurai.com/pub/postfix/official/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/postfix/official/&,}
MASTER_SITE_SUBDIR=	. old related/postfix
DISTNAME=	postfix-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

PATCH_DIST_STRIP=	-p1

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An alternative to widely-used Sendmail

CONFLICTS=	courier-0.* postfix-2.* sendmail-8.* sendmail-*-8.* smail-3.* zmailer-2.*

LATEST_LINK=	${PORTNAME}1
USE_SUBMAKE=	yes
USE_RC_SUBR=	postfix.sh

PATCH_STRIP=	-p1

OPTIONS=	PCRE		"Perl Compatible Regular Expressions"			on \
		SASL		"Cyrus SASLv1 (Simple Auth. and Sec. Layer)"		off \
		TLS		"Enable SSL and TLS support"				off \
		DB3		"Berkeley DB3 (required if SASL built with DB3)"	off \
		MYSQL		"MySQL maps lookups"					off \
		PGSQL		"PostgreSQL maps lookups"				off \
		OPENLDAP	"OpenLDAP maps lookups (BROKEN)"			off \
		IPV6		"IPv6 support (not KAME official)"			off \
		TEST		"SMTP/LMTP test server and generator"			off

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postqueue.1 \
	postsuper.1 sendmail.1

MAN5=	access.5 aliases.5 canonical.5 pcre_table.5 regexp_table.5 \
	relocated.5 transport.5 virtual.5

MAN8=	bounce.8 cleanup.8 defer.8 error.8 flush.8 lmtp.8 local.8 \
	master.8 nqmgr.8 pickup.8 pipe.8 qmgr.8 qmqpd.8 showq.8 smtp.8 \
	smtpd.8 spawn.8 trivial-rewrite.8 virtual.8

CONF1=	main.cf master.cf access aliases canonical pcre_table regexp_table \
	relocated transport virtual

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

MAKEFILEFLAGS+=	CC="${CC}" OPT="${CFLAGS}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" POSTFIX_OPTIONS="${POSTFIX_OPTIONS}"

.include <bsd.port.pre.mk>

# Default requirement for postfix rc.d script
_REQUIRE=	DAEMON

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lpcre
.else
POSTFIX_CCARGS+=	-DNO_PCRE
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl.8:${PORTSDIR}/security/cyrus-sasl
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lsasl -lpam -lcrypt
.endif

.if defined(WITH_TLS)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
MAN8+=			tlsmgr.8
POSTFIX_CCARGS+=	-DHAS_SSL -I${OPENSSLINC}
POSTFIX_AUXLIBS+=	-L${OPENSSLLIB} ${LDFLAGS} -lssl -lcrypto
DISTFILES+=		${DISTNAME}.tar.gz pfixtls-0.8.11a-1.1.11-0.9.6g.tar.gz
EXTRA_PATCHES+=		${WRKDIR}/pfixtls-0.8.11a-1.1.11-0.9.6g/pfixtls.diff
PLIST_SUB+=		SUB_TLS=""
.else
PLIST_SUB+=		SUB_TLS="@comment "
.endif

.if defined(WITH_DB3)
LIB_DEPENDS+=		db3.3:${PORTSDIR}/databases/db3
POSTFIX_CCARGS+=	-I${LOCALBASE}/include/db3
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -ldb3
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lz -lcrypt -lm
_REQUIRE+=		mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
POSTFIX_CCARGS+=	-DHAS_PGSQL -I${LOCALBASE}/include -I${LOCALBASE}/pgsql/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/pgsql/lib -lpq -lcrypt
PATCH_SITES+=		http://mat.cc/postfix/
PATCHFILES+=		postfix-pg.postfix-1.1.8.patch
_REQUIRE+=		postgresql
.endif

.if defined(WITH_OPENLDAP)
BROKEN=			does not support OPENLDAP
USE_OPENLDAP=		yes
.if defined(WITH_OPENLDAP_VER)
USE_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lldap -llber
_REQUIRE+=		slapd
.endif

.if defined(WITH_IPV6)
.if ${ARCH} != i386
BROKEN=			only supported in i386
.endif
.if defined(WITH_TLS)
BROKEN=			IPv6 and TLS patch cannot be used simultaneously
.endif
PATCH_SITES+=		http://www.uinet.or.jp/~taka/misc/
PATCHFILES+=		postfix-1.1.11+ipv6.patch.gz
.endif

.if defined(WITH_TEST)
BIN1=			smtp-sink smtp-source
PLIST_SUB+=		SUB_TEST=""
.else
BIN1=			# empty
PLIST_SUB+=		SUB_TEST="@comment "
.endif

.if defined(NOPORTDOCS)
READMEDIR=		no
.else
READMEDIR=		${PREFIX}/share/doc/postfix
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}"

pre-patch:
.if defined(POSTFIX_OPTIONS)
		@${ECHO_MSG}
		@${ECHO_MSG}
		@${ECHO_MSG}
		@${ECHO_MSG} "***** ALERT *****"
		@${ECHO_MSG} "POSTFIX_OPTIONS don't work anymore, now"
		@${ECHO_MSG} "${PORTNAME} use OPTIONS, consider use:"
		@${ECHO_MSG} "# make config"
		@${ECHO_MSG}
		@${ECHO_MSG}
		@${ECHO_MSG}
		@sleep 10
.endif
.for f in ${MAN1}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man1/${f} ${WRKSRC}/html/${f}.html
.endfor
.for f in ${MAN5}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man5/${f} ${WRKSRC}/html/${f}.html
.endfor
.for f in ${MAN8base}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man8/${f} ${WRKSRC}/html/${f}.html
.endfor
.for f in faq rate rewrite uce
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/html/${f}.html
.endfor
.for f in ${CONF1}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" ${WRKSRC}/conf/${f}
.endfor

post-patch:
# All files modified with ${FILESDIR}/patch-* to use !!PREFIX!! need REINPLACE. Put below.
	@${REINPLACE_CMD} -e "s,!!PREFIX!!,${PREFIX},g" \
		${WRKSRC}/conf/main.cf ${WRKSRC}/src/global/mail_params.h

do-configure:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.init makefiles ${MAKEFILEFLAGS} \
		CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}" && \
		${ECHO_CMD} "all: default" >> Makefile)

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	(cd ${WRKSRC}; ${SH} postfix-install -non-interactive install_root=/ tempdir=/tmp \
		config_directory=${PREFIX}/etc/postfix \
		daemon_directory=${PREFIX}/libexec/postfix \
		command_directory=${PREFIX}/sbin \
		queue_directory=/var/spool/postfix \
		sendmail_path=${PREFIX}/sbin/sendmail \
		newaliases_path=${PREFIX}/bin/newaliases \
		mailq_path=${PREFIX}/bin/mailq \
		mail_owner=postfix \
		setgid_group=maildrop \
		manpage_directory=${PREFIX}/man \
		sample_directory=${PREFIX}/etc/postfix \
		readme_directory=${READMEDIR} )

.for f in ${CONF1}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${PREFIX}/etc/postfix/sample-${f}
.endfor

	@${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/rmail/rmail ${PREFIX}/bin/rmail

# optional TEST binaries
.for f in ${BIN1}
	@${INSTALL_PROGRAM} ${WRKSRC}/src/smtpstone/${f} ${PREFIX}/sbin
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@(cd ${WRKSRC}/html && ${INSTALL_DATA} *.html *.gif ${DOCSDIR} && \
		${ECHO_MSG} "Installed HTML documentation in ${DOCSDIR}" )
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@# Fix compressed man pages
	@${REINPLACE_CMD} -E -e "s|(man[158]/.*.[158]):|\1.gz:|g" ${PREFIX}/etc/postfix/postfix-files
	@${RM} -f ${PREFIX}/etc/postfix/postfix-files.bak
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
