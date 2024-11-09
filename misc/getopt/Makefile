PORTNAME=	getopt
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${UTIL_LINUX_PORTVERSION:R}/
DISTNAME=	util-linux-${UTIL_LINUX_PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for getopt(1) that supports GNU-style long options
WWW=		https://github.com/util-linux/util-linux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig shebangfix tar:xz

CONFIGURE_ARGS=	--disable-asciidoc \
		--disable-all-programs \
		--disable-gtk-doc \
		--disable-nls \
		--disable-makeinstall-chown \
		--disable-makeinstall-setuid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes

SHEBANG_FILES=	misc-utils/getopt-example.bash

UTIL_LINUX_PORTVERSION=	2.39.4

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
