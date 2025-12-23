PORTNAME=	calc
PORTVERSION=	2.16.0.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Interactive CLI arbitrary-precision calculator
WWW=		https://github.com/lcn2/calc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL

FLAVORS=	default tiny

USES=		gmake tar:bzip2 readline
USE_GITHUB=	yes
GH_ACCOUNT=	lcn2

MAKE_ARGS=	DATADIR="${DATADIR}"
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check

CONFLICTS_INSTALL=	schilyutils
PLIST_SUB+=	VERSION=${PORTVERSION} VERSION_R=${PORTVERSION:R}

OPTIONS_DEFINE=	FULL HELP
OPTIONS_DEFAULT=FULL HELP
OPTIONS_SUB=	yes
FULL_DESC=	Install all funcs/scripts/headers (OFF: just basic calculator)
HELP_DESC=	Install calc help files

.if ${FLAVOR:U} == tiny
OPTIONS_EXCLUDE=FULL HELP
PKGNAMESUFFIX=	-tiny
MAKE_ENV+=	BLD_TYPE=calc-static-only
PLIST_FILES=	bin/calc
PLIST=		# Use only PLIST_FILES
CONFLICTS_INSTALL+=	calc
.else
CONFLICTS_INSTALL+=	calc-tiny
.endif

.include <bsd.port.pre.mk>
# We use Makefile.freebsd because Makefile.local is in our .gitignore
post-extract:
	${SED} -e 's|%%CC%%|${CC}|; s|%%CFLAGS%%|${CFLAGS}|; s|%%SH%%|${SH}|' \
		${FILESDIR}/Makefile.freebsd > ${WRKSRC}/Makefile.local
# The upstream Makefiles are a mess. Bash is hardcoded in many files, and only
# some of the Makefiles allow overrides. Plus, they error out if sed .bkp files exist.
	${FIND} ${WRKSRC} -name 'Makefile*' \
		| ${XARGS} ${REINPLACE_CMD} -i '' -E -e '/SHELL:?=/s|bash|${SH}|'

.if ${FLAVOR:U} == default
post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/calc lib/lib*.so

.else
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/calc ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
