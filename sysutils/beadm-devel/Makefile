# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	1.2.99.20180630
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
MASTER_SITES=	GH \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		LOCAL/bdrewery/${PORTNAME}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_TAGNAME=	25fdbf6ef0866dd9d46a32d5879d9e509ecf4025

NO_BUILD=	YES

CONFLICTS_INSTALL=	beadm-[0-9]*

PLIST_FILES=	sbin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	  ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
