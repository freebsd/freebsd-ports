# $FreeBSD$

PORTNAME=	coreutils
PORTVERSION=	8.25
CATEGORIES=	sysutils textproc
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Free Software Foundation core utilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	idutils-[0-9]*

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
# A rather nasty hack to stop gnustat from conflicting with base gstat
# bugs.freebsd.org/160060
CONFIGURE_ARGS=	--program-prefix=g	\
		--program-transform-name=s/stat/nustat/
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		cpe gmake iconv perl5 charsetfix tar:xz
USE_PERL5=	build	# build - required for tests and man page generation
USE_LDCONFIG=	yes

INFO=		coreutils
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	GMP NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_WITH=	gmp

post-build:
	@${REINPLACE_CMD} -e "s/ lib / /g" ${WRKSRC}/Makefile
	@${TOUCH} ${WRKSRC}/doc/coreutils.info

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/libexec/coreutils/libstdbuf.so

#regression-test: build
#	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
