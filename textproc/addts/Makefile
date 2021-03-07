# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	addts
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.gnu.org.ua/release/addts/ \
		ftp://download.gnu.org.ua/release/addts/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Prepend current timestamp to every line of input text

LICENSE=	GPLv3+

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/addts share/man/man1/addts.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/tv_usec/s,%06,&l,' ${WRKSRC}/addts.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
