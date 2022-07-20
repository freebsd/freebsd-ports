PORTNAME=	pymailq
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Postfix queue control python tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	postfix:mail/postfix

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g; \
		s|%%MANPREFIX%%|${MANPREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
