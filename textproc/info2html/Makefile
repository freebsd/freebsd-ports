# Created by: wosch
# $FreeBSD$

PORTNAME=	info2html
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	wenheping@gmail.com
COMMENT=	Translate GNU info files into HTML pages

NO_BUILD=	yes
PLIST_FILES=	bin/info2html bin/infocat bin/info2html.css bin/info2html.conf

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info2html ${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/infocat ${LOCALBASE}/bin
	${INSTALL_DATA} ${WRKSRC}/info2html.conf ${LOCALBASE}/bin
	${INSTALL_DATA} ${WRKSRC}/info2html.css ${LOCALBASE}/bin
.include <bsd.port.mk>
