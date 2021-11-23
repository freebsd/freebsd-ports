# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	exabgp
PORTVERSION=	4.2.13
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GH \
		ZI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	zi@FreeBSD.org
COMMENT=	BGP engine and route injector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	exabgp

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes

SHEBANG_FILES=	etc/exabgp/run/*.run etc/exabgp/run/*.pl \
		etc/exabgp/run/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks

USERS=		_bgpd
GROUPS=		_bgpd

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|exabgp.env|${ETCDIR}/exabgp.env|' \
		${WRKSRC}/lib/exabgp/application/bgp.py
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/doc/man/exabgp.1 \
		${WRKSRC}/lib/exabgp/configuration/usage.py \
		${WRKSRC}/lib/exabgp/configuration/process/parser.py \
		${WRKSRC}/lib/exabgp/application/flow.py \
		${WRKSRC}/lib/exabgp/application/healthcheck.py \

post-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/exabgp.env ${STAGEDIR}${ETCDIR}/exabgp.env.sample

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/etc/exabgp && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
