# New ports collection makefile for:	smtpfeed
# Date created:		17 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	smtpfeed
PORTVERSION=	1.18
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

RUN_DEPENDS=	${LOCALBASE}/sbin/sendmail:${PORTSDIR}/mail/sendmail

NO_PACKAGE=	"complex configuration for sendmail.cf needed"

GNU_CONFIGURE=	yes

MAN8=		smtpfeed.8

PORTDOCS=	COPYRIGHT FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
		OPTIONS OPTIONS.j README README.j RELEASE.NOTE SIGNAL \
		SIGNAL.j TODO smtpfeed.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtpfeed ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>
