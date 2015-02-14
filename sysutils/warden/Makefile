# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warden
PORTVERSION=	1422974289
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Warden jail management system utility

LICENSE=	BSD

RUN_DEPENDS=	${LOCALBASE}/share/pcbsd/scripts/functions.sh:${PORTSDIR}/sysutils/pcbsd-libsh \
		jailme:${PORTSDIR}/sysutils/jailme

WRKSRC=		${WRKDIR}/warden
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
