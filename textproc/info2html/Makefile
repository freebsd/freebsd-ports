PORTNAME=	info2html
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	wenheping@gmail.com
COMMENT=	Translate GNU info files into HTML pages

USES=		shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/info2html bin/infocat bin/info2html.css bin/info2html.conf
SHEBANG_FILES=	info2html infocat

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/infocat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/info2html.conf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/info2html.css ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
