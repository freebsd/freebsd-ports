# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/development%20branch/${PORTVERSION}
PKGNAMEPREFIX=	diary-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal workout diary program for bodybuilders

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlobject>=0.7:${PORTSDIR}/databases/py-sqlobject \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

USES=		gettext
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
WX_COMPS=	python

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
		${WRKSRC}/Hercules/globals.py
post-install:
	@${CHMOD} +r ${PREFIX}/share/${PORTNAME}/xrc/*.xrc

.include <bsd.port.mk>
