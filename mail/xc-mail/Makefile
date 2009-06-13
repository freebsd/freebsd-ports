# New ports collection makefile for:	xc-mail
# Date created:		2000-10-01
# Whom:			trevor
#
# $FreeBSD$
#

PORTNAME=	xc-mail
PORTVERSION=	2.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	xcmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail client for X which supports POP and PGP

LIB_DEPENDS=	Xclasses.1:${PORTSDIR}/x11-toolkits/xclasses

DEPRECATED=	depends on a port that expired in 2007
EXPIRATION_DATE=	2009-06-27

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	arm i386
USE_GMAKE=	yes
USE_XORG=	x11

CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib/

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|expr $1|expr -- $1|g" ${WRKSRC}/plugins/linkshared.in
	@${REINPLACE_CMD} -e "s|expr $1|expr -- $1|g" ${WRKSRC}/src/linktool

post-install:
		chown ${BINOWN}:mail ${PREFIX}/bin/xc-mail
		chmod g+s ${PREFIX}/bin/xc-mail

.include <bsd.port.mk>
