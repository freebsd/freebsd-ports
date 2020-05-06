# $FreeBSD$

PORTNAME=	qiskit-aer
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator for quantum circuits, including noise models

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	undefined reference to `__atomic_load'

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenblas.so:math/openblas \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

PLIST_FILES=	bin/qasm_simulator

.include <bsd.port.mk>
