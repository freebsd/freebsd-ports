# Created by: sumikawa@FreeBSD.org
# $FreeBSD$

PORTNAME=	lv
PORTVERSION=	4.51.20200728
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	sue@iwmt.org
COMMENT=	Powerful Multilingual File Viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../GPL.txt

USES=		ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	ttdoda
GH_TAGNAME=	f7ba677

WRKSRC_SUBDIR=	src
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-${GH_TAGNAME}; \
		${INSTALL_DATA} *.html hello.sample* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
