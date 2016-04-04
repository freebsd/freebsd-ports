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

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES+=		tk
RUN_DEPENDS=	identify:graphics/ImageMagick \
		weblint:www/weblint

NO_BUILD=	yes

PORTDOCS=	specchars.txt
PLIST_FILES=	bin/august

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/august

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/august ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/specchars.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
