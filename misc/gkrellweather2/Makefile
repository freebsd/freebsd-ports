# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gkrellweather
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	misc geography
MASTER_SITES=	https://sites.google.com/site/makovick/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weather plugin for GKrellM

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		gettext gmake pkgconfig tar:tgz
MAKE_ENV=	enable_nls=1
ALL_TARGET=	gkrellweather.so

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} GrabWeather \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	(cd ${WRKSRC} && ${INSTALL_LIB} gkrellweather.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/ru
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ru.mo \
		${STAGEDIR}${PREFIX}/share/locale/ru/LC_MESSAGES/gkrellweather.mo)

.include <bsd.port.mk>
