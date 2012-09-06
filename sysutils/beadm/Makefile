# New ports collection makefile for:	beadm
# Date created:		26 April 2012
# Whom:			Bryan Drewery <bryan@shatow.net>
#
# $FreeBSD$
#

PORTNAME=	beadm
PORTVERSION=	0.8
CATEGORIES=	sysutils
MASTER_SITES=	SF/beadm/dist/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_COMMIT=	b0cdd0c

NO_BUILD=	YES

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
