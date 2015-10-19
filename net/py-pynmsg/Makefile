# $FreeBSD$

PORTNAME=	pynmsg
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for net/nmsg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libnmsg.so:${PORTSDIR}/net/nmsg

USE_PYTHON=	distutils autoplist
USES=		python shebangfix uniquefiles:dirs

SHEBANG_FILES=	examples/*.py

PORTEXAMPLES=	*

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_nmsg.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
