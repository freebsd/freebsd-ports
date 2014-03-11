# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils
PORTVERSION=	1394538598
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Command-Line Utilities

RUN_DEPENDS=	pkg-static:${PORTSDIR}/ports-mgmt/pkg \
		svn:${PORTSDIR}/devel/subversion \
		mksquashfs:${PORTSDIR}/sysutils/squashfs-tools \
		debootstrap:${PORTSDIR}/sysutils/debootstrap \
		sipcalc:${PORTSDIR}/net-mgmt/sipcalc \
		eject:${PORTSDIR}/sysutils/eject \
		unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_PKGNAMEPREFIX}requests1>=1.0.0:${PORTSDIR}/www/py-requests1 \
		jailme:${PORTSDIR}/sysutils/jailme

WRKSRC=		${WRKDIR}/src-sh
CONFLICTS?=	pbi-manager-[0-9]*
USES=		pkgconfig fuse
NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

do-install:
	cd ${WRKSRC} && make install PREFIX=${STAGEDIR}${PREFIX}

post-install:
	PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
