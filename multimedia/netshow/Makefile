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
		http://voodoo.bawue.com/download/
DISTNAME=	netshow_linux
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft NetShow video stream player

DEPRECATED=     Distfile is no more available
EXPIRATION_DATE=        2011-05-01

RESTRICTED=	"Commercial software"

BROKEN=		does not fetch

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
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
