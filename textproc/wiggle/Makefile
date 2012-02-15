# New ports collection Makefile for:	wiggle
# Date created:				2012-02-15
# Whom:					mandree@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wiggle
PORTVERSION=	0.8.0.${_GITDATE}
CATEGORIES=	textproc
#MASTER_SITES=	http://neil.brown.name/wiggle/
MASTER_SITES=	LOCAL/mandree
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.xz

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Apply rejected patches and perform word-wise diffs

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

_GITDATE=	20111208
_GITVERSION=	405d8fe

WRKSRC=		${WRKDIR}/${PORTNAME}-${_GITVERSION}
USE_GMAKE=	yes
USE_XZ=		yes

CFLAGS+=	-Wall -Wstrict-prototypes -Wextra -Wno-unused-parameter
MAKE_ENV+=	CFLAGS="${CFLAGS}"
MAKE_ARGS+=	-e

MAN1=		wiggle.1
PLIST_FILES=	bin/wiggle

build-tarball: ${DISTFILES}
${DISTFILES}.gz:
		${FETCH_CMD} -o ${DISTFILES}.gz 'http://neil.brown.name/git?p=wiggle;a=snapshot;h=${_GITVERSION};sf=tgz'
${DISTFILES}: ${DISTFILES}.gz
		${GZIP_CMD} -cd ${DISTFILES}.gz | ${XZ_CMD} -c --best >${DISTFILES}

upload-tarball: build-tarball
		scp ${DISTFILES} freefall.freebsd.org:public_distfiles/

pre-patch:
		${REINPLACE_CMD} -Ee 's/#include.*<malloc.h>/#include <stdlib.h>/' ${WRKSRC}/*.[ch]
		${REINPLACE_CMD} -Ee 's,\./dotest,bash ./dotest,' ${WRKSRC}/Makefile
		${REINPLACE_CMD} -Ee "s,/usr/bin/time -o .time -f '%U',," ${WRKSRC}/dotest

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/wiggle ${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/wiggle.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
