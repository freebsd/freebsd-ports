PORTNAME=	noto
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website-2.storage.googleapis.com/pkgs/
DISTNAME=	Noto-hinted
PKGNAMESUFFIX=	-extra

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Extra)
WWW=		https://fonts.google.com/noto

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-d ${EXTRACT_WRKDIR} -x '*.otf'
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@cd ${WRKSRC} && ${RM} \
		NotoColorEmoji* \
		NotoEmoji-* \
		NotoSans-* \
		NotoSansMono-* \
		NotoSansSymbols-* \
		NotoSansSymbols2-* \
		NotoSerif-*

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
