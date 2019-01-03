# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	sqlmap
PORTVERSION=	1.2.12
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Automatic SQL injection tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/sqlmap/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:-2.7 shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	*.py sqlmap/extra/shutils/*.sh sqlmap/extra/shutils/*.py
NO_ARCH=	yes

OPTIONS_DEFINE=	MSF
MSF_DESC=	Enable Metasploit Framework integration

MSF_RUN_DEPENDS=	msfcli:security/metasploit

.include <bsd.port.mk>
