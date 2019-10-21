# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	1.3.0
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	\
		LOCAL/bdrewery/${PORTNAME} \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH

MAINTAINER=	vermaden@interia.pl
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden

NO_BUILD=	YES
NO_ARCH=	YES

CONFLICTS_INSTALL=	beadm-devel-*

PLIST_FILES=	sbin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	  ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
