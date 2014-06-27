# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	bcfg2
PORTVERSION=	1.1.1
PORTREVISION=	0
CATEGORIES=	sysutils python
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/bcfg/ \
		http://mirror.opensysadmin.com/bcfg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dhutty@allgoodbits.org
COMMENT=	A configuration management system written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gamin.py:${PORTSDIR}/devel/py-gamin
# bypass infrastructure bug

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS_DEFINE=	CHEETAH GENSHI
CHEETAH_DESC=	Support Cheetah Templates
GENSHI_DESC=	Support Genshi Templates

.include <bsd.port.options.mk>

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Bcfg2

USE_RC_SUBR=	bcfg2
PYDISTUTILS_PKGNAME=	Bcfg2
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.if ${PORT_OPTIONS:MCHEETAH}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah>0:${PORTSDIR}/devel/py-cheetah
.endif

.if ${PORT_OPTIONS:MGENSHI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>0:${PORTSDIR}/textproc/py-genshi
.endif

PORTDOCS=	AUTHORS COPYRIGHT README

post-patch:
	    @${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py
.for f in bcfg2 bcfg2-admin bcfg2-build-reports bcfg2-info bcfg2-repo-validate bcfg2-server bcfg2-ping-sweep
	@${REINPLACE_CMD} -i '' -e 's|/etc/bcfg2.conf|${PREFIX}/etc/bcfg2.conf|g' ${WRKSRC}/src/sbin/$f
.endfor

.for f in 'Options.py' 'Server/Core.py'
	@${REINPLACE_CMD} -i '' -e 's|/etc/bcfg2.conf|${PREFIX}/etc/bcfg2.conf|g' ${WRKSRC}/src/lib/$f
.endfor

.for f in 'Options.py'
	@${REINPLACE_CMD} -i '' -e 's|DEFAULT_INSTALL_PREFIX = ./usr.|DEFAULT_INSTALL_PREFIX = "${PREFIX}"|' ${WRKSRC}/src/lib/$f
	@${REINPLACE_CMD} -i '' -e 's|/var/lock|/var/run|' ${WRKSRC}/src/lib/$f
.endfor

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
