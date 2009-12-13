# New ports collection makefile for:   abgx360
# Date created:        21 November 2009
# Whom:                okeeblow <root@cooltrainer.org>
#
# $FreeBSD$
#

PORTNAME=	abgx360
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://abgx360.x-scene.com/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Verify and repair Xbox 360 backup images

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

PLIST_FILES=	bin/abgx360

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360 ${PREFIX}/bin

.include <bsd.port.mk>
