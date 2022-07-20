PORTNAME=	dvips2ascii
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	SF/srezic/${PORTNAME}/${PORTVERSION}

MAINTAINER=	slaven@rezic.de
COMMENT=	PostScript (created by dvips) to ASCII converter

USES=		shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/dvips2ascii
SHEBANG_FILES=	dvips2ascii

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dvips2ascii ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
