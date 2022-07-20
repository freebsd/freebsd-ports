PORTNAME=	tblis
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Framework for performing tensor operations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: include_configs.hpp:2:10: fatal error: 'configs/armv7a/config.hpp' file not found
BROKEN_armv6=		fails to compile: include_configs.hpp:2:10: fatal error: 'configs/armv7a/config.hpp' file not found
BROKEN_powerpc64=	fails to compile: include_configs.hpp:2:10: fatal error: 'configs/power7/config.hpp' file not found
BROKEN_powerpc64le=	fails to compile: include_configs.hpp:2:10: fatal error: 'configs/power7/config.hpp' file not found
BROKEN_riscv64=		fails to configure: ./tci/tci_config.h:37:2: Unknown architecture
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	i386 requires SSE

OPTIONS_DEFINE=	PARA
PARA_DESC=	use pthread parallelization
OPTIONS_DEFAULT=	PARA

USES=		compiler:c++11-lang gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	devinamatthews

HAS_CONFIGURE=	yes

PARA_CONFIGURE_ON=	--enable-thread-model=pthreads
PARA_CONFIGURE_OFF=	--enable-thread-model=none

INSTALL_TARGET=	install-strip

post-patch:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	@${REINPLACE_CMD} -i .c++20 's/-I/-iquote/g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
