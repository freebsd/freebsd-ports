# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	sshfs
PORTVERSION=	3.4.0
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mount remote directories over ssh

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		fuse:3 gettext meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	libfuse

USE_GNOME=	glib20
CFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/sshfs \
		man/man1/sshfs.1.gz

.include <bsd.port.mk>
