# $FreeBSD$

PORTNAME=	mininet
PORTVERSION=	2.3.0d1
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	akoshibe@gmail.com
COMMENT=	Emulator for rapid prototyping of software defined networks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	help2man>=0:misc/help2man
RUN_DEPENDS=	iperf>=0:benchmarks/iperf \
		openvswitch>=0:net/openvswitch \
		${PYTHON_PKGNAMEPREFIX}ryu>=0:net/ryu@${PY_FLAVOR} \
		socat>=0:net/socat \
		bash:shells/bash

USES=		python:2.7
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	akoshibe
GH_TAGNAME=	b88c58c

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	@${CC} ${WRKSRC}/mnexec.c -o ${BUILD_WRKSRC}/mnexec
	@help2man -N -n "create a Mininet network."  --no-discard-stderr \
		"${PYTHON_CMD} -B ${BUILD_WRKSRC}/bin/mn" -o ${BUILD_WRKSRC}/mn.1
	@help2man -N -n "execution utility for Mininet."  -h "-h" -v "-v" \
		--no-discard-stderr ${BUILD_WRKSRC}/mnexec -o ${BUILD_WRKSRC}/mnexec.1
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mnexec ${STAGEDIR}${PREFIX}/bin
.for m in mnexec mn
	${INSTALL_MAN} ${BUILD_WRKSRC}/$m.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL} -d ${STAGEDIR}${PREFIX}/share/doc/mininet
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.md ${STAGEDIR}${PREFIX}/share/doc/mininet
	${INSTALL} -d ${STAGEDIR}${PREFIX}/share/examples/mininet
.for f in examples/README.md examples/*.py
	${INSTALL_DATA} ${BUILD_WRKSRC}/$f ${STAGEDIR}${PREFIX}/share/examples/mininet
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
.endfor

.include <bsd.port.mk>
