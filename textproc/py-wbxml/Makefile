# New ports collection makefile for:	py-wbxml
# Date Created:				13 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	wbxml
PORTVERSION=	0.1
CATEGORIES=	textproc python
MASTER_SITES=	SF/synce
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@logvinov.com
COMMENT=	Python bindings for the wbxml2 library

LIB_DEPENDS=	wbxml2.0:${PORTSDIR}/textproc/wbxml2
BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_PYTHON=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pywbxml.a \
		%%PYTHON_SITELIBDIR%%/pywbxml.la \
		%%PYTHON_SITELIBDIR%%/pywbxml.so

DEPRECATED=	No longer supported by developers
EXPIRATION_DATE=	2009-01-24

.include <bsd.port.mk>
