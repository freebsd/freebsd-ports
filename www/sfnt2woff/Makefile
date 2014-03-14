# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfnt2woff
PORTVERSION=	20091004
CATEGORIES=	www converters
MASTER_SITES=	http://people.mozilla.org/~jkew/woff/
DISTNAME=	woff-code-latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert TTF/OTF fonts to WOFF web embeddable format and back

NO_WRKSUBDIR=	yes
USES=		gmake zip

PLIST_FILES=	bin/sfnt2woff bin/woff2sfnt

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sfnt2woff ${WRKSRC}/woff2sfnt \
		 ${PREFIX}/bin

.include <bsd.port.mk>
