# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	busybox
PORTVERSION=	1.21.0
CATEGORIES=	sysutils misc shells
MASTER_SITES=	http://www.busybox.net/downloads/
PKGNAMESUFFIX=	-unstable

#PATCH_SITES=	http://www.busybox.net/downloads/fixes-${PORTVERSION}/
#PATCH_DIST_STRIP=	-p1
#PATCHFILES=	\

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Busybox for FreeBSD

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

CONFLICTS_INSTALL=	busybox-[1-9]*

PORTSCOUT=	limitw:1,ODD

MAKE_JOBS_SAFE=	yes
MAKE_ARGS+=	SKIP_STRIP=y CC="${CC}" HOSTCC="${CC}" CXX="${CXX}" HOSTCXX="${CXX}"
USE_BZIP2=	yes
USE_GMAKE=	yes
# avoid clang, breaks in findutils/find.c l. 752+,
# uses a GCC extension/invalid C code:
USE_GCC?=	4.2+

PLIST_FILES=	bin/busybox

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_PERL5_BUILD=	yes
PORTDOCS=		*
.endif

post-patch:
	${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/scripts/gen_build_files.sh
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/libbb/appletlib.c \
		${WRKSRC}/shell/hush.c
	${REINPLACE_CMD} -e 's/<alloca.h>/<stdlib.h>/' \
		${WRKSRC}/scripts/basic/*.c

do-configure:
	${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} oldconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
	${RM} -f ${DOCSDIR}/.gitignore
.endif

.include <bsd.port.mk>
