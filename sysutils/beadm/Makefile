# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	SF/beadm/dist/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_COMMIT=	a7c1c73

NO_BUILD=	YES

CONFLICTS_INSTALL=	beadm-devel-*

PLIST_FILES=	sbin/${PORTNAME} \
		man/man1/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	  ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
