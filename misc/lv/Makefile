PORTNAME=	lv
PORTVERSION=	4.51.20200728
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	sue@iwmt.org
COMMENT=	Powerful Multilingual File Viewer
WWW=		https://github.com/ttdoda/lv

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../GPL.txt

USES=		ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	ttdoda
GH_TAGNAME=	f7ba677

WRKSRC_SUBDIR=	src
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}; \
		${INSTALL_DATA} *.html hello.sample* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
