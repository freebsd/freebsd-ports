# New ports collection makefile for:	postfix
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

# To pre-select options in batch mode, run make like this:
#
#  make -DBATCH POSTFIX_OPTIONS="DB3 IPv6TLS"
#
# the options are the same names as in the scripts/configure.postfix file.
# POSTFIX_OPTIONS can be set in /etc/make.conf also.

# NOTE: PCRE is enabled by default unless you specifically disable it.

PORTNAME=	postfix
PORTVERSION=	2.2.3
PORTREVISION=	1
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

MAINTAINER=	vivek@khera.org
COMMENT=	A secure alternative to widely-used Sendmail

CONFLICTS=	courier-0.* postfix-1.* postfix-2.0.* postfix-2.1.* postfix-2.3.* \
		sendmail-8.* sendmail-*-8.* smail-3.* zmailer-2.*
USE_SUBMAKE=	yes
USE_REINPLACE=	yes

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 postfix.1 \
	postkick.1 postlock.1 postlog.1 postmap.1 postqueue.1 postsuper.1 sendmail.1

MAN5=	access.5 aliases.5 body_checks.5 canonical.5 cidr_table.5 generic.5 \
	header_checks.5 ldap_table.5 master.5 mysql_table.5 nisplus_table.5 \
	pcre_table.5 pgsql_table.5 postconf.5 regexp_table.5 relocated.5 \
	transport.5 virtual.5

MAN8=	anvil.8 bounce.8 cleanup.8 defer.8 discard.8 error.8 flush.8 lmtp.8 \
	local.8 master.8 oqmgr.8 pickup.8 pipe.8 proxymap.8 qmgr.8 qmqpd.8 \
	scache.8 showq.8 smtp.8 smtpd.8 spawn.8 tlsmgr.8 trace.8 trivial-rewrite.8 \
	verify.8 virtual.8

CONF1=	access aliases canonical generic header_checks main.cf master.cf \
	relocated transport virtual

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

MAKEFILEFLAGS+=	CC="${CC}" OPT="${CFLAGS}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		POSTFIX_OPTIONS="${POSTFIX_OPTIONS}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.postfix

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.if defined(WITHOUT_PCRE)
POSTFIX_CCARGS+=	-DNO_PCRE
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lpcre
.endif

post-patch:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.init makefiles ${MAKEFILEFLAGS} \
	CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}" && \
	${ECHO} "all: default" >> Makefile)

pre-patch:
	@${ECHO} "<body>See <A HREF="header_checks.5.html">header_checks.5.html</A></BODY>" > ${WRKSRC}/html/body_checks.5.html
	@for f in `${FIND} -P ${WRKSRC}/man -type f`; do \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" $${f}; \
	done
	@for f in `${FIND} -P ${WRKSRC}/README_FILES -type f`; do \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" $${f}; \
	done
	@for f in `${FIND} -P ${WRKSRC}/conf -type f`; do \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" $${f}; \
	done

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.if defined(NOPORTDOCS)
READMEDIR=no
.else
READMEDIR=${PREFIX}/share/doc/postfix
.endif

do-install:
	cd ${WRKSRC}; ${SH} postfix-install -non-interactive install_root=/ tempdir=/tmp \
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
	readme_directory=${READMEDIR}

	@${MKDIR} ${PREFIX}/etc/postfix/dist
.for f in ${CONF1}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${PREFIX}/etc/postfix/dist
.endfor

	@${INSTALL_SCRIPT} \
		${WRKSRC}/auxiliary/rmail/rmail \
		${PREFIX}/bin/rmail

# optional TEST binaries
.for file in ${BIN1}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/sbin
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@cd ${WRKSRC}/html && ${INSTALL_DATA} *.html *.jpg *.png ${DOCSDIR} && \
		${ECHO_MSG} "Installed HTML documentation in ${DOCSDIR}"
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
# need to fixup ${PREFIX}/etc/postfix/postfix-files to indicate compressed
# man pages, since the ports software compresses them after this step, and
# if we run etc/postfix/post-install again during package installation,
# it will complain about missing files.
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/fix-files-list
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
