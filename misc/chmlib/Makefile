PORTNAME=	chmlib
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.jedrea.com/chmlib/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-io64 --disable-pread --exec-prefix=${PREFIX} --disable-static --enable-examples
INSTALL_TARGET=	install-strip
USES=		cpe gmake libtool tar:bzip2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
