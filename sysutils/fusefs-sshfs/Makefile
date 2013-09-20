# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	sshfs
PORTVERSION=	2.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/${PORTNAME}-fuse/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-fuse-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Mount remote directories over ssh

KMODDIR?=	${LOCALBASE}/modules

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
USE_GNOME=	glib20

MAN1=	sshfs.1

NO_STAGE=	yes
post-install:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
