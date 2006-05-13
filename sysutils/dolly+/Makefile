# New ports collection makefile for:	dolly+
# Date created:		Thu Jul 15 10:13:27 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dolly+
PORTVERSION=	0.93
CATEGORIES=	sysutils net
MASTER_SITES=	http://corvus.kek.jp/~manabe/pcf/dolly/
DISTNAME=	dolly${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of dolly harddisk/partition network clone utility

NO_WRKSUBDIR=	yes

PROGRAM_BIN_FILES=	dollyC
PROGRAM_SBIN_FILES=	dollyS dping

PLIST_FILES=		bin/dollyC \
			sbin/dollyS \
			sbin/dping

do-configure:
# CXX{,FLAGS}, PTHREAD_* safeness
	@${REINPLACE_CMD} -E \
		-e 's|g\+\+|${CXX}|' \
		-e 's|^(CXXFLAGS[[:space:]]*=.*)$$|\1 ${CXXFLAGS} ${PTHREAD_CFLAGS}|' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
.for file in ${PROGRAM_BIN_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/
.endfor
.for file in ${PROGRAM_SBIN_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin/
.endfor

.include <bsd.port.mk>
