# Created by: Vidar Karlsen <vidar@karlsen.tech>
# $FreeBSD$

PORTNAME=	onetime
PORTVERSION=	1.81
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.red-bean.com/onetime/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Encryption program that uses the one-time pad algorithm

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7 shebangfix
SHEBANG_FILES=	onetime

NO_ARCH=	yes

PLIST_FILES=	bin/onetime

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onetime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
