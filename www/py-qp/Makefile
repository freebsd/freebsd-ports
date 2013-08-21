# New ports collection makefile for:	py-qp
# Date created:		14 Nov 2006
# Whom:	      		Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	qp
PORTVERSION=	2.2
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qp/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python web framework to use qpy and durus together

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}durus>=0:${PORTSDIR}/devel/py-durus \
		${PYTHON_PKGNAMEPREFIX}qpy>=1.7:${PORTSDIR}/www/py-qpy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}durus>=0:${PORTSDIR}/devel/py-durus \
		${PYTHON_PKGNAMEPREFIX}qpy>=1.7:${PORTSDIR}/www/py-qpy

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_ENV=	USE_DISTUTILS=yes
USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.txt LICENSE.txt README.txt ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYSETUP} install_demo_sites ${EXAMPLESDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
