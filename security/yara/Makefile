# New ports collection makefile for:    yara
# Date created:         Mar 7 2011
# Whom:                 wxs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yara
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A malware identification and classification tool

LIB_DEPENDS=	re2.0:${PORTSDIR}/devel/re2

PROJECTHOST=	yara-project
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	"--with-re2"
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

MAN1=	yara.1

.include <bsd.port.mk>
