PORTNAME=	tblis
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for performing tensor operations
WWW=		https://github.com/devinamatthews/tblis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires SSE

USES=		compiler:c++11-lang gmake libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PARA
PARA_DESC=	use pthread parallelization
OPTIONS_DEFAULT=	PARA

USE_GITHUB=	yes
GH_ACCOUNT=	devinamatthews

HAS_CONFIGURE=	yes

PARA_CONFIGURE_ON=	--enable-thread-model=pthreads
PARA_CONFIGURE_OFF=	--enable-thread-model=none

INSTALL_TARGET=	install-strip

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	@${REINPLACE_CMD} -i .c++20 's/-I/-iquote/g' ${WRKSRC}/Makefile.in

do-test:
	(cd ${WRKSRC}/bin && ./test)

.include <bsd.port.mk>
