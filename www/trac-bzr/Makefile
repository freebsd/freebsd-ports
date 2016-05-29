# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	20110228
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Bazaar-NG plugin for Trac

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac \
		bzr:devel/bzr

USES=		python:2 tar:bzip2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|tag_date = 1||' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
