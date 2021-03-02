# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	1.3.2
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	vermaden@interia.pl
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden

NO_BUILD=	YES
NO_ARCH=	YES

CONFLICTS_INSTALL=	beadm-devel-*

PLIST_FILES=	sbin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
	  ${STAGEDIR}${MANPREFIX}/man/man8/

.include <bsd.port.mk>
