PORTNAME=	info_to_html
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.mons.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into HTML pages

USES=		perl5 shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/info_to_html
SHEBANG_FILES=	info_to_html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info_to_html ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
