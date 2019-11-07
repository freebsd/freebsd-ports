# $FreeBSD$

PORTNAME=	hfm
PORTVERSION=	1.2.3
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	554b8425@razorfever.net
COMMENT=	Run tests in parallel at high frequency

LICENSE=	BSD2CLAUSE

BROKEN=		fails to build

# gb 0.4 includes FreeBSD-specific fixes that this port requires
#   https://github.com/constabulary/gb/issues/506
BUILD_DEPENDS=	gb>=0.4:devel/gb \
		${LOCALBASE}/lib/libucl.a:textproc/libucl

USES=		compiler:c++11-lang go:no_targets
USE_GITHUB=	yes

GH_ACCOUNT=	derekmarcotte
GH_TUPLE=	mitchellh:go-libucl:f9d0e55:gu/vendor/src/github.com/mitchellh/go-libucl \
		op:go-logging:dfaf3df:gl/vendor/src/github.com/op/go-logging

USERS=		_hfm
GROUPS=		_hfm

USE_RC_SUBR=	hfm

MAKE_ARGS+=	ETCDIR=${ETCDIR} TAG=${DISTVERSIONPREFIX}${PORTVERSION}

ALL_TARGET=	test build

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	(cd ${WRKSRC}; ${PATCH} vendor/src/github.com/mitchellh/go-libucl/libucl.go < vendor/patches/github.com/mitchellh/go-libucl/libucl.go.patch )

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/hfm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hfm.conf.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
