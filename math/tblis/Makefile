PORTNAME=	tblis
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Framework for performing tensor operations
WWW=		https://github.com/devinamatthews/tblis

BROKEN_FreeBSD_14=	error: static_assert failed due to requirement

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires SSE

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
