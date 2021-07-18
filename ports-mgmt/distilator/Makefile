# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	distilator
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://critical.ch/distilator/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line script to check the availability of a ports distfiles

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.18.4_1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-ftp>=0.3.1:ftp/py-requests-ftp@${PY_FLAVOR}

USES=		python shebangfix

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/distilator
SHEBANG_FILES=	distilator.py

.include <bsd.port.mk>
