# $FreeBSD$

PORTNAME=	textql
PORTVERSION=	g20200203
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Execute SQL against structured text like CSV or TSV

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	dinedal
GH_TAGNAME=	1d6fef5

GO_TARGET=	textql/main.go:textql

PLIST_FILES=	bin/textql \
		man/man1/textql.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/textql.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
