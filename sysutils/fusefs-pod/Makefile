PORTNAME=	pod
PORTVERSION=	0.5.2
PORTREVISION=	16
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/fuse${PORTNAME}/fuse${PORTNAME}/FUSEPod%20v${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fusepod-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE-based filesystem for iPod
WWW=		https://fusepod.sourceforge.net/

LIB_DEPENDS=	libgpod.so:audio/libgpod\
		libtag.so:audio/taglib

USES=		compiler:c++11-lang fuse pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
PLIST_FILES=	bin/fusepod share/man/man1/fusepod.1.gz

.include <bsd.port.mk>
