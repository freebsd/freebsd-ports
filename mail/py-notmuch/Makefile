# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.20.2
CATEGORIES=	mail python
MASTER_SITES=	http://notmuchmail.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	geier@lostpackets.de
COMMENT=	Python binding of the notmuch mail search and indexing library

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/../../COPYING-GPL-3

LIB_DEPENDS=	libnotmuch.so:${PORTSDIR}/mail/notmuch

WRKSRC_SUBDIR=	bindings/python

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

MAKE_ENV+=	PYTHONCMD=${PYTHON_CMD}

.include <bsd.port.mk>
