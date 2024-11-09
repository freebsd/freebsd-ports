PORTNAME=	qiskit-aer
DISTVERSION=	0.10.4
PORTREVISION=	5
CATEGORIES=	science # quantum-computing

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	46d86944f349a177acb40fb8a3adc301c395fe60.patch:-p1 # https://github.com/Qiskit/qiskit-aer/pull/1576

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum circuits simulator submodule of the Qiskit framework
WWW=		https://qiskit.org/aer/ \
		https://github.com/Qiskit/qiskit-aer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_15=	compilation fails with clang-19: error: no member named 'size_' in 'QubitVector<data_t>'
BROKEN_i386=	undefined reference to `__atomic_load' # '

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libopenblas.so:math/openblas \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++11-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

CONFIGURE_ENV=	DISABLE_CONAN=yes

PLIST_FILES=	bin/qasm_simulator

.include <bsd.port.mk>
