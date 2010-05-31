# ex:ts=8
# Ports collection Makefile for:	linsmith
# Date created:			Dec 22, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linsmith
PORTVERSION=	0.99.12
PORTREVISION=	4
CATEGORIES=	science hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.9.12

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Smith charting program

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	pkgconfig libgnomeprint libgnomeui libxml2
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${CP} ${FILESDIR}/carg.c  ${WRKSRC}/src

.include <bsd.port.mk>
