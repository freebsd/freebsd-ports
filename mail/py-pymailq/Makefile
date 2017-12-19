# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pymailq
PORTVERSION=	0.8.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Postfix queue control python tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	postfix:mail/postfix

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils concurrent

PLIST_FILES=	man/man1/pqshell.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g; s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g' \
		${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pqshell.1 ${STAGEDIR}${MANPREFIX}/man/man1/pqshell.1

.include <bsd.port.mk>
