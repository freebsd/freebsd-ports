# New ports collection makefile for:	trac-bzr
# Date created:		2007-03-30
# Whom:			Radim Kolar <hsn@sanatana.dharma>
#
# $FreeBSD$
#

PORTNAME=	bzr
PORTVERSION=	20110228
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Bazaar-NG plugin for Trac

LICENSE=	GPLv2

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac bzr:${PORTSDIR}/devel/bzr

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

USE_BZIP2=	yes

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYTRAC_BZR_EGG=${PYTRAC_BZR_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYTRAC_BZR_EGG=	TracBzr-0.4.2-py${PYTHON_VER}.egg

post-patch:
	${REINPLACE_CMD} -e 's|tag_date = 1||' ${WRKSRC}/setup.cfg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
