# New ports collection makefile for:	smtpfeed
# Date created:		17 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	smtpfeed
PORTVERSION=	1.13
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/ \
		http://freefall.freebsd.org/~itojun/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX} \
		${SENDMAILPATCH}.patch.gz

MAINTAINER=	ports@freebsd.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX}
PATCH_SENDMAIL_ARGS=	-d ${WRKSRC_SENDMAIL} -E ${PATCH_DIST_STRIP}
NO_PACKAGE=	"complex configuration for sendmail.cf needed"

SENDMAILVER=	8.9.3
SENDMAIL=	sendmail.${SENDMAILVER}
SENDMAILDIR=	sendmail-${SENDMAILVER}
SENDMAILPATCH=	sendmail893+3.2W
WRKSRC_SMTPFEED=	${WRKSRC}
WRKSRC_SENDMAIL=	${WRKDIR}/${SENDMAILDIR}/src

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec
# use bind8?
#CONFIGURE_ARGS+=	--with-bind8

DOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
	OPTIONS OPTIONS.j README README.j RELEASE.NOTE SIGNAL SIGNAL.j TODO
DOCDIR=	${PREFIX}/share/doc/smtpfeed

post-patch:
	@${ECHO_MSG} "===>  Applying smtpfeed patch ${SENDMAILPATCH} to ${SENDMAIL}"
	@(cd ${_DISTDIR}; for i in ${SENDMAILPATCH}.patch.gz; do \
		${GZCAT} $$i | ${PATCH} ${PATCH_SENDMAIL_ARGS}; \
	done)

post-build:
	@${ECHO_MSG} "===>  Building patched ${SENDMAIL}"
	@(cd ${WRKSRC_SENDMAIL}; sh makesendmail)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}; \
	done
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

install-sendmail:
	(cd ${WRKSRC_SENDMAIL}; sh makesendmail install)

.include <bsd.port.mk>
