# Created by: trevor
# $FreeBSD$

PORTNAME=	august
PORTVERSION=	0.63b
PORTREVISION=	5
CATEGORIES=	www editors
MASTER_SITES=	http://fossies.org/unix/www/old/ \
		http://www.sourcefiles.org/Editors/HTML/ \
		http://www.erjobe.info/mainwiki/pmwiki/uploads/Main/August/
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor for the experienced Web author

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	identify:graphics/ImageMagick \
		weblint:www/weblint

USES=		tk
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	specchars.txt
PLIST_FILES=	bin/august

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/august

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/august ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/specchars.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
