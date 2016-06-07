# Created by: sumikawa@FreeBSD.org
# $FreeBSD$

PORTNAME=	lv
PORTVERSION=	4.51
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	sue@iwmt.org
COMMENT=	Powerful Multilingual File Viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../GPL.txt

USE_GITHUB=	yes
GH_ACCOUNT=	ttdoda

USES=		ncurses
WRKSRC_SUBDIR=	src
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
		${INSTALL_DATA} *.html hello.sample* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
