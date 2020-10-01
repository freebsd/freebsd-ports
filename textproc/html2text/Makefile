# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	html2text
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Converts HTML documents into plain text

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	grobian

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/html2text man/man1/html2text.1.gz man/man5/html2textrc.5.gz

CONFLICTS=	py27-html2text-[0-9]*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
