PORTNAME=	analitza
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library from KDE Education project
WWW=		https://invent.kde.org/education/analitza

LICENSE=		GFDL GPLv2
LICENSE_COMB=		multi
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.DOC
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang eigen:3 gl kde:6 qt:6 tar:xz
USE_GL=		glu
USE_KDE=	ecm:build
USE_QT=		5compat base svg
USE_LDCONFIG=	yes

SHLIB_VER=	9.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
