# $FreeBSD$
#

PORTNAME=	waitress
PORTVERSION=	0.8.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Python WSGI server

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

# Avoid to install patch files backup
post-patch:
	@cd ${WRKSRC} && \
		${FIND} . -type f -name '*.orig' -exec ${RM} -f \{\} \;

.include <bsd.port.mk>
