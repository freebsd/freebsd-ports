# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	5.2
CATEGORIES=	print ports-mgmt
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-lite

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimal version of texinfo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

PLIST_FILES=	bin/ginstall-info \
		bin/ginfo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_ENV=	PERL=${TRUE} ac_cv_path_PERL=${TRUE}

BUILD_WRKSRC=	${WRKSRC}/gnulib/lib

post-build:
		cd ${WRKSRC}/install-info; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}
		cd ${WRKSRC}/info; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/install-info/ginstall-info ${STAGEDIR}${PREFIX}/bin/ginstall-info
		${INSTALL_PROGRAM} ${WRKSRC}/info/ginfo ${STAGEDIR}${PREFIX}/bin/ginfo

.include <bsd.port.mk>
