# New ports collection makefile for:	smtpfeed
# Date created:		17 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	smtpfeed
PORTVERSION=	1.21
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/smtpfeed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

NO_PACKAGE=	complex configuration for sendmail.cf needed

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

MAN8=		smtpfeed.8
PORTDOCS=	FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
		ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
		RELEASE.NOTE SIGNAL SIGNAL.j TODO smtpfeed.html
PLIST_FILES=	libexec/smtpfeed

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtpfeed ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
