# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exabgp
PORTVERSION=	3.4.19
CATEGORIES=	net
MASTER_SITES=	GH \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	BGP engine and route injector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
USES=		python:2
SUB_FILES=	pkg-message exabgp.sh
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes

USERS=		_bgpd
GROUPS=		_bgpd

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${MV} -f ${WRKSRC}/etc/systemd ${WRKSRC}

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/doc/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
	${INSTALL_DATA} ${FILESDIR}/exabgp.env ${STAGEDIR}${ETCDIR}/exabgp.env.sample

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
