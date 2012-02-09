# New ports collection makefile for:	kpdftool
# Date created:				04 May 2006
# Whom:					Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$
#

PORTNAME=	kpdftool
PORTVERSION=	0.23.1
CATEGORIES=	print kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTFILES=	33194-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to ease your PDF related work

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qt3support moc_build porting_build qmake_build uic3_build
USE_GHOSTSCRIPT_RUN=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"KPDFTool" "${COMMENT}" "kpdftool" \
			"kpdftool" "" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${PREFIX}/share/icons/

.include <bsd.port.mk>
