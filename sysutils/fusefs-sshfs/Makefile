# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	sshfs
PORTVERSION=	2.7
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mount remote directories over ssh

LICENSE=	GPLv2

KMODDIR?=	${LOCALBASE}/modules

USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
GH_TAGNAME=	a9a1cc0

GNU_CONFIGURE=	yes
USES=		autoreconf fuse pkgconfig
USE_GNOME=	glib20

PLIST_FILES=	bin/sshfs \
		man/man1/sshfs.1.gz

.include <bsd.port.mk>
