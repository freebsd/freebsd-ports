PORTNAME=	asl
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.4.3
CATEGORIES=	math
MASTER_SITES=	https://coin-or-tools.github.io/ThirdParty-ASL/:solvers
PKGNAMEPREFIX=	coin-or-
DISTFILES=	solvers-64919f75f.tgz:solvers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	COIN-OR autotools harness to build AMPL Solver Library

LICENSE=	EPL

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or-tools
GH_PROJECT=	ThirdParty-ASL

GNU_CONFIGURE=	yes

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
CFLAGS+=	-DASL_NO_FP_INIT
.endif

post-extract:
	@cd ${WRKSRC} && ${LN} -s ../solvers .

post-patch: # patch the side project
	@cd ${WRKSRC} && \
		(${ECHO} "#include <sys/stat.h>" && cat solvers/funcadd1.c) > solvers/funcadd1.c.new && \
		${MV} solvers/funcadd1.c.new solvers/funcadd1.c

.include <bsd.port.mk>
