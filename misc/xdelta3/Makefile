PORTNAME=	xdelta
PORTVERSION=	3.1.0
PORTREVISION=	3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES?=	misc devel
PKGNAMESUFFIX=	3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

LICENSE=	GPLv2+

USES=		autoreconf compiler:c++11-lang gmake
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jmacd

WRKSRC_SUBDIR=	xdelta3

PLIST_FILES=	bin/xdelta3 man/man1/xdelta3.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/_POSIX_/d ; \
		 /_C99_/d' ${WRKSRC}/xdelta3.h

.include <bsd.port.mk>
