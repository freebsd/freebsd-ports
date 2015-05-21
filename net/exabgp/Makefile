# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exabgp
PORTVERSION=	3.4.8
CATEGORIES=	net
MASTER_SITES=	GH \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	BGP engine and route injector

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
USES=		tar:tgz python:2
SUB_FILES=	pkg-message exabgp.sh
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}

USERS=		_bgpd
GROUPS=		_bgpd

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-extract:
	@${MV} -f ${WRKSRC}/etc/systemd ${WRKSRC}

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif
	${CP} ${FILESDIR}/exabgp.env ${STAGEDIR}${ETCDIR}/exabgp.env.sample

.include <bsd.port.mk>
