PORTNAME=	hunspell
PORTVERSION=	2020.12.31
CATEGORIES=	textproc
MASTER_SITES=	https://extensions.libreoffice.org/assets/downloads/752/
PKGNAMEPREFIX=	sl-
DISTNAME=	pack-sl
EXTRACT_SUFX=	.oxt

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovenian hunspell dictionary
WWW=		https://extensions.libreoffice.org/extensions/slovenian-dictionary-pack/

LICENSE=	LGPL21

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${DATADIR}/sl_SI.aff \
		${DATADIR}/sl_SI.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sl_SI.aff ${WRKSRC}/sl_SI.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
