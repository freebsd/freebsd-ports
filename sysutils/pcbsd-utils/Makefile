# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils
PORTVERSION=	1382605460
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
		${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:${PORTSDIR}/www/py-requests \
		jailme:${PORTSDIR}/sysutils/jailme

WRKSRC=		${WRKDIR}/src-sh
CONFLICTS?=	pbi-manager-[0-9]*
NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
IGNORE=		requires FreeBSD 9.0 or later
.endif

.if ${OSVERSION} > 1000000
PLIST_FILES+=	share/pbi-manager/.pbime \
		share/pbi-manager/.pbimount \
		share/pbi-manager/.ldconfig \
		share/pbi-manager/.mount_nullfs \
		etc/man.d/pbi.conf \
		sbin/app \
		sbin/pbi
.endif

do-install:
	cd ${WRKSRC} && make install PREFIX=${STAGEDIR}${PREFIX}

post-install:
	PKG_PREFIX=${STAGEDIR}${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
