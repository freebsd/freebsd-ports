# Created by: Sergey Skvortsov <skv@protey.ru>

PORTNAME=	MathModePlugin
SVNREV=		15934
PORTREVISION=	1
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		LOCAL/skv

COMMENT=	Include LaTeX formatted math in your TWiki pages

USES=		magick:6,run

USE_TEX=	base latex

post-patch:
	${REINPLACE_CMD} -i '' -e 's!=/usr/bin!=${LOCALBASE}/bin!g; s!=/bin!=/usr/bin!g;' \
		${WRKSRC}/pub/TWiki/MathModePlugin/latex2img

.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
