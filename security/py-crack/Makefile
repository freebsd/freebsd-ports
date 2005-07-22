# New ports collection makefile for:	py-crack
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	pycrack
PORTVERSION=	0.5
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	python-crack/Stable.pkg/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-crack-${PORTVERSION}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Python bindings to cracklib

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYSETUP=	distutil.py
GNU_CONFIGURE=	yes

PLIST_FILES:=	${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,}/_crack.so \
		${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,}/crack.py

CONFIGURE_ENV=	"CPPFLAGS=-I${LOCALBASE}/include" \
		"LDFLAGS=-L${LOCALBASE}/lib" \
		"DEFAULT_DICTPATH=${LOCALBASE}/libdata/cracklib/pw_dict"

MAKE_ENV=	"CPPFLAGS=-I${LOCALBASE}/include -fPIC" \
		"LDFLAGS=-L${LOCALBASE}/lib"

post-install:
	${INSTALL_DATA} ${WRKSRC}/crack.py ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
