PORTNAME=	getopt
PORTVERSION=	2.41.1
CATEGORIES=	misc
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v${PORTVERSION:R}/
DISTNAME=	util-linux-${PORTVERSION}

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
		--disable-year2038 \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes

SHEBANG_FILES=	misc-utils/getopt-example.bash

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

.include <bsd.port.mk>
