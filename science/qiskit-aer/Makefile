# $FreeBSD$

PORTNAME=	qiskit-aer
DISTVERSION=	0.4.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator for quantum circuits, including noise models

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	spdlog>0:devel/spdlog
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenblas.so:math/openblas
RUN_DEPENDS=	spdlog>0:devel/spdlog

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

PLIST_FILES=	bin/qasm_simulator

.include <bsd.port.mk>
