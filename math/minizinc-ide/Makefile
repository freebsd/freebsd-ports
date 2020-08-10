# $FreeBSD$

PORTNAME=	minizinc-ide
DISTVERSION=	2.4.3
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IDE for MiniZinc, a constraint modeling language

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	minizinc:math/minizinc

USES=		gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	MiniZinc
GH_PROJECT=	MiniZincIDE
USE_QT=		core declarative gui location network printsupport webchannel webengine widgets buildtools_build

USE_GL=		gl

PLIST_FILES=	bin/MiniZincIDE

.include <bsd.port.mk>
