# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	20110228
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Bazaar-NG plugin for Trac

BROKEN=		unfetchable
DEPRECATED=	Broken, uses EOLed python27
EXPIRATION_DATE=	2020-02-19

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac \
		bzr:devel/bzr

USES=		python:2.7 tar:bzip2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|tag_date = 1||' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
