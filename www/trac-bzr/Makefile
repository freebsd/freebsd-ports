# New ports collection makefile for:	trac-bzr
# Date created:		2007-03-30
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	bzr
PORTVERSION=	20090604
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://home.tiscali.cz/~cz210552/bsdports/tarballs/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Bazaar-NG plugin for Trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

USE_BZIP2=	yes

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYTRAC_BZR_EGG=${PYTRAC_BZR_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYTRAC_BZR_EGG=	TracBzr-0.2-py${PYTHON_VER}.egg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
