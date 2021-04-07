PORTNAME=	pyobd
DISTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www.obdtester.com/download/
DISTNAME=	pyobd_${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBD-II compliant car diagnostic tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	convert:graphics/ImageMagick6
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR}

USES=		dos2unix gnome python shebangfix
DOS2UNIX_FILES=	${PORTNAME}.desktop
SHEBANG_FILES=	${PORTNAME}
USE_WX=		3.0
WX_COMPS=	python

INSTALLS_ICONS=	yes

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	@convert ${WRKSRC}/${PORTNAME}.gif ${WRKSRC}/${PORTNAME}.png

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${WRKSRC}/*.py ${WRKSRC}/*.pyc \
		${STAGEDIR}${DATADIR}
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${LN} -sf ../share/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
