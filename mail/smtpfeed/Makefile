# New ports collection makefile for:	smtpfeed
# Version required:	0.66
# Date created:		17 January 1998
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.10 1998/06/22 18:48:47 itojun Exp $
#

DISTNAME=	smtpfeed-0.66
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/ \
		ftp://ftp.sendmail.org/ucb/src/sendmail/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX} \
		${SENDMAILPATCH}.patch.gz

MAINTAINER=	itojun@itojun.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${SENDMAIL}${EXTRACT_SUFX}
PATCH_SENDMAIL_ARGS=	-d ${WRKSRC_SENDMAIL} -E ${PATCH_DIST_STRIP}
NO_PACKAGE=	"complex configuration for sendmail.cf needed"

SENDMAIL=	sendmail.8.8.8
SENDMAILDIR=	sendmail-8.8.8
SENDMAILPATCH=	sendmail888+3.0Wb13
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
	@(cd ${WRKSRC_SENDMAIL}; sh Patch-makefiles)

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
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGDIR}/MESSAGE

install-sendmail:
	(cd ${WRKSRC_SENDMAIL}; sh makesendmail install)

.include <bsd.port.mk>
