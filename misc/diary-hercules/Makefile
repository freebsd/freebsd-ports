# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/development%20branch/${PORTVERSION}
PKGNAMEPREFIX=	diary-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal workout diary program for bodybuilders

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlobject>=0.7:databases/py-sqlobject \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3

USES=		gettext python
USE_PYTHON=	distutils
USE_WX=		2.6+
WX_UNICODE=	yes
WX_COMPS=	python

post-patch:
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
		${WRKSRC}/Hercules/globals.py
post-install:
	@${CHMOD} +r ${STAGEDIR}${PREFIX}/share/${PORTNAME}/xrc/*.xrc

.include <bsd.port.mk>
