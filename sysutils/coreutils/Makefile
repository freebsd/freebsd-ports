# $FreeBSD$

PORTNAME=	coreutils
PORTVERSION=	8.31
CATEGORIES=	sysutils textproc
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Free Software Foundation core utilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	idutils-[0-9]*

USES=		cpe gmake iconv perl5 charsetfix tar:xz
CPE_VENDOR=	gnu
USE_PERL5=	build	# required for tests and man page generation
USE_LDCONFIG=	yes
TEST_TARGET=	check

GNU_CONFIGURE=	yes
# A rather nasty hack to stop gnustat from conflicting with base gstat
# bugs.freebsd.org/160060
CONFIGURE_ARGS=	--program-prefix=g	\
		--program-transform-name=s/stat/nustat/
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1

INFO=		coreutils

OPTIONS_DEFINE=	GMP NLS
OPTIONS_SUB=	yes
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_WITH=	gmp
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-build:
	@${REINPLACE_CMD} -e "s/ lib / /g" ${WRKSRC}/Makefile
	@${TOUCH} ${WRKSRC}/doc/coreutils.info

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/libexec/coreutils/libstdbuf.so

.include <bsd.port.mk>
