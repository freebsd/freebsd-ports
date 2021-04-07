PORTNAME=	fontobene
DISTVERSION=	0.2.0
CATEGORIES=	x11-fonts

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++/Qt5 FontoBene font parser library

LICENSE=		APACHE20 MIT
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		core buildtools_build qmake_build # core is needed for build to be checked by cmake, and for run because it is included from the headers

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-qt5

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
