# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	20110228
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Bazaar-NG plugin for Trac

LICENSE=	GPLv2

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac \
		bzr:${PORTSDIR}/devel/bzr

USE_BZIP2=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	TracBzr
PYDISTUTILS_PKGVERSION=	0.4.2
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|tag_date = 1||' ${WRKSRC}/setup.cfg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
