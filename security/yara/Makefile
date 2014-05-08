# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	2.1.0
CATEGORIES=	security

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A malware identification and classification tool

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic
GH_TAGNAME=	2.1.0
GH_COMMIT=	1f0559b

USE_AUTOTOOLS=	libtool aclocal autoheader automake
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	@cd ${WRKSRC} && ${SH} ./bootstrap.sh

pre-install:
	${STRIP_CMD} ${WRKSRC}/libyara/.libs/libyara.so.2

.include <bsd.port.mk>
