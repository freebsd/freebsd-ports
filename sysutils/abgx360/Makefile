# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	abgx360
PORTVERSION=	1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://abgx360.x-scene.com/ \
		http://update.cooltrainer.org/freebsd-ports/sysutils/abgx360/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Verify and repair Xbox 360 backup images

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

BROKEN_ia64=	does not compile
BROKEN_powerpc=	does not compile
BROKEN_sparc64=	does not compile

PLIST_FILES=	bin/abgx360

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
