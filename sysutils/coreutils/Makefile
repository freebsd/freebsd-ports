# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	coreutils
PORTVERSION=	8.22
PORTREVISION=	2
CATEGORIES=	sysutils textproc
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Software Foundation core utilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	id-utils-[0-9]* linux-gid-[0-9]*

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
# A rather nasty hack to stop gnustat from conflicting with base gstat
# bugs.freebsd.org/160060
CONFIGURE_ARGS=	--program-prefix=g	\
		--program-transform-name=s/stat/nustat/
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		gmake iconv perl5 charsetfix
USE_PERL5=	build	# build - required for tests and man page generation
USE_XZ=		yes
USE_LDCONFIG=	yes

INFO=		coreutils

OPTIONS_DEFINE=	GMP NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=   nls
GMP_LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp
GMP_CONFIGURE_WITH=	gmp

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 800039
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-stty.c
.endif

post-build:
	@${REINPLACE_CMD} -e "s/ lib / /g" ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/libexec/coreutils/glibstdbuf.so

#regression-test: build
#	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} check)

.include <bsd.port.mk>
