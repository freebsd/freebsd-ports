PORTNAME=	sshfs
PORTVERSION=	3.7.3
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a73501f2159875aef082ab0a61731a8b7673d477.patch:-p1 # https://github.com/libfuse/sshfs/pull/212

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mount remote directories over ssh

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 fuse:3 gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
USE_GNOME=	glib20

CFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/sshfs

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rst2man:textproc/py-docutils
DOCS_PLIST_FILES=	man/man1/sshfs.1.gz

.include <bsd.port.mk>
