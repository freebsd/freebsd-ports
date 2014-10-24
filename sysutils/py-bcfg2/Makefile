# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	bcfg2
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/bcfg/ \
		http://mirror.opensysadmin.com/bcfg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Configuration management system written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}lockfile>0:${PORTSDIR}/devel/py-lockfile \
		${PYTHON_PKGNAMEPREFIX}daemon>0:${PORTSDIR}/devel/py-daemon \
		${PYTHON_SITELIBDIR}/gamin.py:${PORTSDIR}/devel/py-gamin

OPTIONS_DEFINE=	CHEETAH GENSHI
CHEETAH_DESC=	Support Cheetah Templates
GENSHI_DESC=	Support Genshi Templates

.include <bsd.port.options.mk>

USES=		python
USE_PYTHON=	distutils autoplist

USE_RC_SUBR=	bcfg2
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.if ${PORT_OPTIONS:MCHEETAH}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah>0:${PORTSDIR}/devel/py-cheetah
.endif

.if ${PORT_OPTIONS:MGENSHI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>0:${PORTSDIR}/textproc/py-genshi
.endif

PORTDOCS=	COPYRIGHT README

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -i '' -e 's|/etc/bcfg2.conf|${PREFIX}/etc/bcfg2.conf|g' ${WRKSRC}/src/sbin/*

.for f in 'Options.py' 'Server/models.py'
	@${REINPLACE_CMD} -i '' -e 's|/etc/bcfg2.conf|${PREFIX}/etc/bcfg2.conf|g' ${WRKSRC}/src/lib/Bcfg2/$f
.endfor

.for f in 'Options.py'
	@${REINPLACE_CMD} -i '' -e 's|DEFAULT_INSTALL_PREFIX = ./usr.|DEFAULT_INSTALL_PREFIX = "${PREFIX}"|' ${WRKSRC}/src/lib/Bcfg2/$f
	@${REINPLACE_CMD} -i '' -e 's|/var/lock|/var/run|' ${WRKSRC}/src/lib/Bcfg2/$f
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
