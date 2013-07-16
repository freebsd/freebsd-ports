# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A malware identification and classification tool

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

PROJECTHOST=	yara-project
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

MAN1=	yara.1

.include <bsd.port.mk>
