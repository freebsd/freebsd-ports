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

LICENSE=	GPLv2

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac \
		bzr:${PORTSDIR}/devel/bzr

USE_BZIP2=	yes
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${REINPLACE_CMD} -e 's|tag_date = 1||' ${WRKSRC}/setup.cfg

post-install:
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
