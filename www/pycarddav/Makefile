# $FreeBSD$

PORTNAME=	pycarddav
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyCardDAV-${PORTVERSION}

MAINTAINER=	samir@noir.im
COMMENT=	Simple to use CardDAV CLI client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>0:deskutils/py-vobject@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>0:devel/py-urwid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PLIST_FILES+=	man/man1/pc_query.1.gz \
		man/man1/pycard-import.1.gz \
		man/man1/pycardsyncer.1.gz

PORTEXAMPLES=	pycard.conf.sample

SUB_FILES=	pkg-message

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pycard.conf.sample ${STAGEDIR}${EXAMPLESDIR}/pycard.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
