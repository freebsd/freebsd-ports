# New ports collection makefile for:	postfix-current
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
PORTVERSION=	2.0.18
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

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	postfix-2.0-ns-mx-acl-patch.gz

MAINTAINER=	khera@kciLink.com
COMMENT=	A secure alternative to widely-used Sendmail

CONFLICTS=	courier-0.* postfix-1.* sendmail-8.* sendmail-*-8.* smail-3.* zmailer-2.*
USE_SUBMAKE=	yes
USE_REINPLACE=	yes

MAN1=	mailq.1 newaliases.1 postalias.1 postcat.1 postconf.1 postdrop.1 \
	postfix.1 postkick.1 postlock.1 postlog.1 postmap.1 postqueue.1 \
	postsuper.1 sendmail.1

MAN5=	access.5 aliases.5 canonical.5 pcre_table.5 regexp_table.5 \
	relocated.5 transport.5 virtual.5

MAN8=	bounce.8 cleanup.8 defer.8 error.8 flush.8 lmtp.8 local.8 \
	master.8 nqmgr.8 pickup.8 pipe.8 proxymap.8 qmgr.8 qmqpd.8 showq.8 \
	smtp.8 smtpd.8 spawn.8 trivial-rewrite.8 virtual.8

# TLS patch adds to MAN8 but doesn't have .html file, so avoid trying to
# patch it.
MAN8base=$(MAN8:S/tlsmgr.8//)

CONF1=	main.cf master.cf access aliases canonical pcre_table regexp_table \
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
.for file in ${MAN1}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man1/${file} ${WRKSRC}/html/${file}.html
.endfor
.for file in ${MAN5}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man5/${file} ${WRKSRC}/html/${file}.html
.endfor
.for file in ${MAN8base}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/man/man8/${file} ${WRKSRC}/html/${file}.html
.endfor
.for file in faq rate rewrite uce
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" \
		${WRKSRC}/html/${file}.html
.endfor
.for file in ${CONF1}
	@${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g" ${WRKSRC}/conf/${file}
.endfor

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

.for file in ${CONF1}
	${INSTALL_DATA} ${WRKSRC}/conf/${file} \
		${PREFIX}/etc/postfix/sample-${file}
.endfor

	@${INSTALL_SCRIPT} \
		${WRKSRC}/auxiliary/rmail/rmail \
		${PREFIX}/bin/rmail

# optional TEST binaries
.for file in ${BIN1}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/src/smtpstone/${file} \
		${PREFIX}/sbin
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@cd ${WRKSRC}/html && ${INSTALL_DATA} *.html *.gif ${DOCSDIR} && \
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
