# New ports collection makefile for:	smtpfeed
# Date created:		17 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	smtpfeed
PORTVERSION=	1.20
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/smtpfeed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

NO_PACKAGE=	"complex configuration for sendmail.cf needed"

GNU_CONFIGURE=	yes

MAN8=		smtpfeed.8

MYPORTDOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
		ML-ADMIN ML-ADMIN.j \
		OPTIONS OPTIONS.j README README.j RELEASE.NOTE SIGNAL \
		SIGNAL.j TODO smtpfeed.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtpfeed ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>
