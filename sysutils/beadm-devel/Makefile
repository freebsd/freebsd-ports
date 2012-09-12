# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	0.8.99.20120912
CATEGORIES=	sysutils
MASTER_SITES=	http://github.com/${GH_ACCOUNT}/${PORTNAME}/tarball/${GH_COMMIT}/
PKGNAMESUFFIX=	-devel
DISTNAME=	${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD

FETCH_ARGS=	-Fpr
GH_ACCOUNT=	vermaden
GH_COMMIT=	3eb4ac9

NO_BUILD=	YES

CONFLICTS_INSTALL=	beadm-[0-9]*

PLIST_FILES=	sbin/${PORTNAME}

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		not supported on 7.x
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
