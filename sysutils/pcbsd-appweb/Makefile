# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-appweb
PORTVERSION=	1422974666
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Web Interface

LICENSE=	BSD

RUN_DEPENDS=	syscache:${PORTSDIR}/sysutils/pcbsd-syscache \
		pbi:${PORTSDIR}/sysutils/pbi-manager \
		warden:${PORTSDIR}/sysutils/warden \
		nginx:${PORTSDIR}/www/nginx

DEFAULT_PHP_VER=55
IGNORE_WITH_PHP=54
USE_PHP=	gd filter session
WRKSRC=		${WRKDIR}/src-webui
USES=		pkgconfig tar:xz
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

do-install:
	cd ${WRKSRC} && make install PREFIX=${STAGEDIR}${PREFIX}

post-install:
	PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
