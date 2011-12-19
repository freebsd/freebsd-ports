# New ports collection makefile for:	fusefs-sshfs
# Date created: 			01 October 2005
# Whom:					Anish Mistry
# $FreeBSD$
#

PORTNAME=	sshfs
PORTVERSION=	2.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/${PORTNAME}-fuse/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-fuse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount remote directories over ssh

KMODDIR?=	${LOCALBASE}/modules

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${KMODDIR}/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
USE_GNOME=	glib20

MAN1=	sshfs.1

post-install:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
