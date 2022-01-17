PORTNAME=	napi
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	polish multimedia

MAINTAINER=	dominik.lisiak@bemsoft.pl
COMMENT=	Command line subtitles downloader for napiprojekt.pl

LICENSE=	GPLv3

RUN_DEPENDS=	7zz:archivers/7-zip \
		base64:converters/base64 \
		bash:shells/bash \
		mediainfo:multimedia/mediainfo \
		wget:ftp/wget

USES=		cmake shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	hesperos
GL_PROJECT=	${PORTNAME}
GL_COMMIT=	ac404649571e470bf9494f788bd8a74843956851

SHEBANG_GLOB=	*.sh *.sh.in

STRIP=
NO_ARCH=	yes

OPTIONS_DEFINE=	COVER NFO RMORIG SUBRIP UTF8

COVER_DESC=	Always try to download cover (-c)
NFO_DESC=	Always try to download .nfo file (-n)
RMORIG_DESC=	Always remove intermediate files (-d)
SUBRIP_DESC=	Convert subtitles to SubRip (.srt) by default (-f subrip)
UTF8_DESC=	Convert subtitles to UTF-8 by default (-C UTF-8)

NAPI_CONF=	libs/libnapi_sysconf.sh

post-patch-COVER-on:
	@${REINPLACE_CMD} -e 's|\(napiprojekt\.cover\.download\)=0|\1=1|' ${WRKSRC}/${NAPI_CONF}

post-patch-NFO-on:
	@${REINPLACE_CMD} -e 's|\(napiprojekt\.nfo\.download\)=0|\1=1|' ${WRKSRC}/${NAPI_CONF}

post-patch-RMORIG-on:
	@${REINPLACE_CMD} -e 's|\(napiprojekt\.subtitles\.orig\.delete\)=0|\1=1|' ${WRKSRC}/${NAPI_CONF}

post-patch-SUBRIP-on:
	@${REINPLACE_CMD} -e 's|\(napiprojekt\.subtitles\.format\)=default|\1=subrip|' ${WRKSRC}/${NAPI_CONF}

post-patch-UTF8-on:
	@${REINPLACE_CMD} -e 's|\(napiprojekt\.subtitles\.encoding\)=default|\1=UTF-8|' ${WRKSRC}/${NAPI_CONF}

post-install:
	@${RM} -r ${STAGEDIR}${LOCALBASE}/lib/napi/*.in

.include <bsd.port.mk>
