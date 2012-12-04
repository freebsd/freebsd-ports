# Created by: ijliao
# $FreeBSD$

PORTNAME=	linsmith
PORTVERSION=	0.99.24
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GNOME=	libgnomeui libxml2
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GCC=	any

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${CP} ${FILESDIR}/carg.c  ${WRKSRC}/src

.include <bsd.port.mk>
