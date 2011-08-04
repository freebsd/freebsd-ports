# ex:ts=8
# Ports collection Makefile for:	linsmith
# Date created:			Dec 22, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linsmith
PORTVERSION=	0.99.22
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smith charting program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GNOME=	libgnomeui libxml2
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${CP} ${FILESDIR}/carg.c  ${WRKSRC}/src

.include <bsd.port.mk>
