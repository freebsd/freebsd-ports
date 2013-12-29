# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	2.0.0
CATEGORIES=	security

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A malware identification and classification tool

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic
GH_TAGNAME=	v2.0.0
GH_COMMIT=	d5dbefb

USE_AUTOTOOLS=	libtool aclocal autoheader automake
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=	yara.1

NO_STAGE=	yes

pre-configure:
	@cd ${WRKSRC} && ${SH} ./bootstrap.sh

.include <bsd.port.mk>
