# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	librdkafka
PORTVERSION=	0.9.1
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache Kafka C/C++ library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	edenhill

USES=		gmake perl5 python shebangfix ssl
SHEBANG_FILES=	lds-gen.py
GNU_CONFIGURE=	yes
MAKE_ENV=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000 && ${ARCH} == "i386"
CFLAGS+=	-march=pentium
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.post.mk>
