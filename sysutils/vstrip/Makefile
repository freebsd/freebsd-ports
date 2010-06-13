# New ports collection makefile for:	vstrip
# Date created:		Mon Jan  2 18:13:03 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vstrip
DISTVERSION=	0.8f
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://files.digital-digest.com/downloads/files/encode/
DISTNAME=	vStrip_${DISTVERSION:C/\.//g}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A VOB de-multiplexing tool, splitter and VOB/IFO files processor

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USE_ZIP=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_SAFE=	yes

post-extract:
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 -x -n 10 \
		${REINPLACE_CMD} -E \
			-e 's|[[:cntrl:]]$$||'
post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|malloc.h|stdlib.h|' \
		-e 's|<io.h>|<unistd.h>|' \
		-e 's|__int64[[:space:]]+fposition[[:space:]]*=[[:space:]]*_filelengthi64\(fp\);|off_t fposition=lseek(fp, 0, SEEK_END);|' \
		${WRKSRC}/*.c \
		${WRKSRC}/*.h

LDFLAGS+=	-lm

PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
