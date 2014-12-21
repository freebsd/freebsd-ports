# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	childtickets
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://schema.filez.com/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Support for having child-tickets in Trac

LICENSE=	BSD3CLAUSE

RUN_DEPENDS+=	trac>=0.12:${PORTSDIR}/www/trac

USES=		zip

WRKSRC=		${WRKDIR}/childticketsplugin/0.12

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
