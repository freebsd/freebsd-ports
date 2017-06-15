# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	abgx360
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://abgx360.xecuter.com/dl/ \
		http://update.cooltrainer.org/freebsd-ports/sysutils/abgx360/ \
		http://dl.dropbox.com/u/59058148/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Verify and repair Xbox 360 backup images

BUILD_DEPENDS=	curl:ftp/curl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/abgx360

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
