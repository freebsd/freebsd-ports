# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	sqlmap
PORTVERSION=	1.1.9
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Automatic SQL injection tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/sqlmap/doc/COPYING

NO_ARCH=	yes
USES=		python:-2.7 shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	*.py sqlmap/extra/shutils/*.sh

OPTIONS_DEFINE=	MSF
MSF_DESC=	Enable Metasploit Framework integration

MSF_RUN_DEPENDS=	msfcli:security/metasploit

.include <bsd.port.mk>
