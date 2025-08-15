PORTNAME=	calc
PORTVERSION=	2.16.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Interactive CLI arbitrary-precision calculator
WWW=		https://github.com/lcn2/calc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL

USES=		gmake tar:bzip2 readline
USE_GITHUB=	yes
GH_ACCOUNT=	lcn2

CONFLICTS_INSTALL=	schilyutils # bin/calc

MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	VERSION=${PORTVERSION} VERSION_R=${PORTVERSION:R}

MAKE_ARGS=	DATADIR="${DATADIR}"
TEST_TARGET=	check

OPTIONS_DEFINE=	FULL HELP
OPTIONS_DEFAULT=FULL HELP
OPTIONS_SUB=	yes
FULL_DESC=	Install all funcs/scripts/headers (OFF: just basic calculator)
HELP_DESC=	Install calc help files

# We use Makefile.freebsd because Makefile.local is in .gitignore
post-extract:
	${SED} -e 's|%%CC%%|${CC}|; s|%%CFLAGS%%|${CFLAGS}|; s|%%SH%%|${SH}|' \
		${FILESDIR}/Makefile.freebsd > ${WRKSRC}/Makefile.local
# The upstream Makefiles are a mess. Bash is hardcoded in many files, and only
# some of the Makefiles allow overrides. Plus, they error out if sed .bkp files exist.
	${FIND} ${WRKSRC} -name 'Makefile*' \
		| ${XARGS} ${REINPLACE_CMD} -i '' -E -e '/SHELL:?=/s|bash|${SH}|'

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/calc lib/lib*.so

.include <bsd.port.mk>
