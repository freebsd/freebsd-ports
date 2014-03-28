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

PLIST_FILES=	bin/abgx360

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-abgx360.c
.endif

.if ${OSVERSION} > 900000
.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif
.endif

.include <bsd.port.post.mk>
