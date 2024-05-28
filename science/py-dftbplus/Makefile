PORTNAME=	dftbplus
DISTVERSION=	24.1
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFTB+: Package for performing fast atomistic simulations
WWW=		https://dftbplus.org/

LICENSE=	GPLv3 # main code is under LGPL3+, the bundled dftd3-lib is under GPLv1+, this makes the result GPLv3 (based on https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility)

RUN_DEPENDS=	dftbplus>0:science/dftbplus

USES=		compiler:gcc-c++11-lib fortran python shebangfix

SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

WRKSRC_SUBDIR=	tools/pythonapi

NO_ARCH=	yes

.include <bsd.port.mk>
