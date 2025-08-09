PORTNAME=	qiskit-aer
DISTVERSION=	0.16.0.1
PORTREVISION=	2
CATEGORIES=	science # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum circuits simulator submodule of the Qiskit framework
WWW=		https://qiskit.org/aer/ \
		https://github.com/Qiskit/qiskit-aer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	undefined reference to `__atomic_load' # '
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenblas.so:math/openblas \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++11-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CONFIGURE_ENV=	DISABLE_CONAN=yes

PLIST_FILES=	qiskit_aer/backends/controller_wrappers

.include <bsd.port.mk>
