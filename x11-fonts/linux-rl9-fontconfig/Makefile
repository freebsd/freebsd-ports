PORTNAME=	fontconfig
PORTVERSION=	2.14.0
DISTVERSIONSUFFIX=	-2.el9_1
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/wiki/Software/fontconfig/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	brotli expat freetype harfbuzz libxml2
USE_LINUX_RPM=	yes

CPE_VENDOR=	fontconfig_project

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/lib/fontconfig \
		${WRKSRC}/usr/share/fontconfig

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${PREFIX}/var/db/fontconfig

.include <bsd.port.mk>
