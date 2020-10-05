# $FreeBSD$

PORTNAME=	fontobene
DISTVERSION=	0.1.0-2
DISTVERSIONSUFFIX=	-gb57b075
CATEGORIES=	x11-fonts

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++/Qt5 FontoBene font parser library

LICENSE=		APACHE20 MIT
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		qmake qt:5
USE_QT=		core # workaround for bug#250146

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-qt5

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
