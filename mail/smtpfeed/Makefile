# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	smtpfeed
PORTVERSION=	1.21
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/smtpfeed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-Wno-error=return-type
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

MAN8=		smtpfeed.8
PORTDOCS=	FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
		ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
		RELEASE.NOTE SIGNAL SIGNAL.j TODO smtpfeed.html
PLIST_FILES=	libexec/smtpfeed

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtpfeed ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
