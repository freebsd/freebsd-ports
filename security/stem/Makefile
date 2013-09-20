# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	stem
PORTVERSION=	1.0.1
CATEGORIES=	security net python
MASTER_SITES=	http://www.atagar.com/transfer/tmp/ \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python controller library for Tor

LICENSE=	GPLv3

RUN_DEPENDS=	tor:${PORTSDIR}/security/tor

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
