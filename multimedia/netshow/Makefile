# New ports collection makefile for:    netshow
# Date created:         Thu Jun 11 22:38:52 PDT 1998
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netshow
PORTVERSION=	2.00.251
PORTREVISION=	2
CATEGORIES=	multimedia linux net
MASTER_SITES=	ftp://ftp.mayn.de/pub/really_old_stuff/unix/browser/plugins/ \
		http://voodoo.oberon.net/download/
DISTNAME=	netshow_linux
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft NetShow video stream player

RESTRICTED=	"Commercial software"

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
PLIST_FILES=	bin/netshow

pre-extract:
	@${MKDIR} ${WRKDIR}

do-extract:
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netshow

do-build:
	${BRANDELF} -t Linux ${WRKDIR}/netshow

do-install:
	${INSTALL} -c -o bin -g bin -m 555 ${WRKDIR}/netshow ${PREFIX}/bin/netshow

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
