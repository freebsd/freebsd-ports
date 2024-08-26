PORTNAME=	coreutils
DISTVERSION=	9.5
CATEGORIES=	sysutils textproc
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Free Software Foundation core utilities
WWW=		https://www.gnu.org/software/coreutils/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe iconv perl5 charsetfix tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_PERL5=	build	# required for tests and man page generation

GNU_CONFIGURE=	yes
# A rather nasty hack to stop gnustat from conflicting with base gstat
# bugs.freebsd.org/160060
CONFIGURE_ARGS=	--program-prefix=g	\
		--program-transform-name=s/stat/nustat/
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1

TEST_TARGET=	check
PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	gdu geneweb gexpr rubygem-god # bin/gdu bin/gexpr bin/god bin/gwc

INFO=		coreutils

OPTIONS_DEFINE=	GMP NLS
OPTIONS_SUB=	yes
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_WITH=	gmp
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-build:
	@${REINPLACE_CMD} -e "s/ lib / /g" ${WRKSRC}/Makefile
	@${TOUCH} ${WRKSRC}/doc/coreutils.info

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/g* \
		${STAGEDIR}${PREFIX}/libexec/coreutils/libstdbuf.so

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--disable-year2038
.endif

.include <bsd.port.mk>
