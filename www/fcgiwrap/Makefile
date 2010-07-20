# New ports collection makefile for:	fcgiwrap
# Date created:		2010-06-15
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcgiwrap
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/gnosek/fcgiwrap/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Simple FastCGI wrapper for CGI scripts

LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

WRKSRC=		${WRKDIR}/gnosek-fcgiwrap-2e301c8
LICENSE=	MIT

USE_AUTOTOOLS=	autoconf:262:env autoheader:262

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

MAN8=		fcgiwrap.8
PLIST_FILES=	sbin/fcgiwrap

post-patch:
	@${REINPLACE_CMD} 's/@prefix@@mandir@/@mandir@/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
