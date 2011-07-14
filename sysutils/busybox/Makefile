# New ports collection makefile for:	busybox
# Date created:         Aug.18, 2008
# Whom:                 luigi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	busybox
PORTVERSION=	1.18.5
PORTREVISION=	1
CATEGORIES=	sysutils misc shells
MASTER_SITES=	http://www.busybox.net/downloads/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Busybox for FreeBSD

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

MAKE_JOBS_SAFE=	yes
MAKE_ARGS+=	SKIP_STRIP=y
USE_BZIP2=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-include libgen.h
# avoid clang, breaks in findutils/find.c l. 752+:
USE_GCC=	4.2+

PLIST_FILES=	bin/busybox

.if !defined(NOPORTDOCS)
USE_PERL5_BUILD=	yes
PORTDOCS=		*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/scripts/gen_build_files.sh
	@${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/libbb/appletlib.c \
		${WRKSRC}/shell/hush.c

do-configure:
	${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} oldconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
	${RM} -f ${DOCSDIR}/.gitignore
.endif

.include <bsd.port.mk>
