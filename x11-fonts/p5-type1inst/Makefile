# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	type1inst
PORTVERSION=	0.6.1
PORTREVISION=	6
CATEGORIES=	x11-fonts perl5
MASTER_SITES=	SUNSITE/X11/xutils
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Script that helps install Postscript fonts in X Window System

USES=		perl5 shebangfix
NO_BUILD=	yes
PORTDOCS=	README

PLIST_FILES=	bin/t1embed bin/type1inst man/man1/type1inst.1.gz
SHEBANG_FILES=	type1inst t1embed

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=X11

X11_RUN_DEPENDS=	${LOCALBASE}/bin/mkfontscale:x11-fonts/mkfontscale

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} type1inst t1embed \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_MAN} ${WRKSRC}/type1inst.man \
		${STAGEDIR}${PREFIX}/man/man1/type1inst.1

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
