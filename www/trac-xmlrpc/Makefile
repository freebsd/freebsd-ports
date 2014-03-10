# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	xmlrpc
PORTVERSION=	1.1.2.r${SVN_REV}
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides an XML-RPC interface to Trac

LICENSE=	BSD

SVN_REV=	13203

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/trunk
FETCH_BEFORE_ARGS=	-o ${DISTFILES}

USES=	zip
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
