PORTNAME=	MathModePlugin
SVNREV=		15934
PORTREVISION=	2
MASTER_SITES=	LOCAL/skv

COMMENT=	Include LaTeX formatted math in your TWiki pages
WWW=		https://twiki.org/cgi-bin/view/Plugins/MathModePlugin

USES=		magick:6,run tex
USE_TEX=	base latex

post-patch:
	${REINPLACE_CMD} -i '' -e 's!=/usr/bin!=${LOCALBASE}/bin!g; s!=/bin!=/usr/bin!g;' \
		${WRKSRC}/pub/TWiki/MathModePlugin/latex2img

.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
