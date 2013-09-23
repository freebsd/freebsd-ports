# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	0.8.99.20130730
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_COMMIT=	d7d7cd3
GH_TAGNAME=	${GH_COMMIT}

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
