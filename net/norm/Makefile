PORTNAME=	norm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.9
CATEGORIES=	net

MAINTAINER=	alven@FreeBSD.org
COMMENT=	NACK-Oriented Reliable Multicast (NORM)
WWW=		https://www.nrl.navy.mil/Our-Work/Areas-of-Research/Information-Technology/NCS/NORM/

LICENSE=	NRL
LICENSE_NAME=	NRL License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

USES=		libtool waf
USE_CXXSTD=	gnu++98
USE_GITHUB=	yes
GH_ACCOUNT=	USNavalResearchLaboratory
GH_PROJECT=	norm
GH_TUPLE=	USNavalResearchLaboratory:protolib:702e909:protolib/protolib
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnorm.so.${DISTVERSION}

post-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
