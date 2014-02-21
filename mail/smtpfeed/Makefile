# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	smtpfeed
PORTVERSION=	1.21
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/smtpfeed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP Fast Exploding External Deliverer for Sendmail

LICENSE=	BSD4CLAUSE

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-Wno-error=return-type
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	FEATURES FEATURES.j FYI FYI.j INSTALL INSTALL.j \
		ML-ADMIN ML-ADMIN.j OPTIONS OPTIONS.j README README.j \
		RELEASE.NOTE SIGNAL SIGNAL.j TODO smtpfeed.html
PLIST_FILES=	libexec/smtpfeed man/man8/smtpfeed.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtpfeed ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/smtpfeed.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
