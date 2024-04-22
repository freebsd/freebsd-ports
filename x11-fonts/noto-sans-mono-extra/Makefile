PORTNAME=	noto
PORTVERSION=	2.014
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/latin-greek-cyrillic/releases/download/NotoSansMono-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-mono-extra
DISTNAME=	NotoSansMono-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Mono (Extra)
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${RM} ${WRKSRC}/NotoSansMono/hinted/ttf/NotoSansMono-Bold.ttf
	@${RM} ${WRKSRC}/NotoSansMono/hinted/ttf/NotoSansMono-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSansMono/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
