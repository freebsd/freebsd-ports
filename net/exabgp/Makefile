# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exabgp
PORTVERSION=	3.2.18
CATEGORIES=	net
MASTER_SITES=	GH GHC \
		http://mirrors.rit.edu/zi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A BGP engine and route injector

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	51d6b56
USE_PYTHON=	yes
SUB_FILES=	pkg-message exabgp.sh
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}

USERS=		_bgpd
GROUPS=		_bgpd

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${MV} -f ${WRKSRC}/etc/systemd ${WRKSRC}

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${PREFIX}/man/man1
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME} ${ETCDIR}
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${PYTHON_SITELIBDIR})
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif
	@if [ ! -f ${ETCDIR}/exabgp.env ]; then \
	    	${CP} ${FILESDIR}/exabgp.env ${ETCDIR} ; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
