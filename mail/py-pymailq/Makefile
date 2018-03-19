# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pymailq
PORTVERSION=	0.9.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Postfix queue control python tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	postfix:mail/postfix

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils concurrent

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g; \
		s|%%MANPREFIX%%|${MANPREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
