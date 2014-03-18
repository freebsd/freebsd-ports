# Created by: dlowe
# $FreeBSD$

PORTNAME=	bulk_mailer
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.utk.edu/pub/moore/bulk_mailer/ \
		LOCAL/mat

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Speeds delivery to mailing lists by sorting & batching addresses

GNU_CONFIGURE=	YES
OPTIONS_DEFINE=	DOCS
LICENSE=	GPLv3

ALL_TARGET=	bulk_mailer

PLIST_FILES=	bin/bulk_mailer man/man1/bulk_mailer.1.gz
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.ps ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
