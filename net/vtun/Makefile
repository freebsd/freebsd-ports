# New ports collection makefile for:	vtun
# Date created:				05 Feb 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vtun
PORTVERSION=	2.5
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	kevlo@FreeBSD.org

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

MAN5=		vtund.conf.5
MAN8=		vtund.8
MLINKS=		vtund.8 vtun.8
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=/var \
		--with-ssl-headers=${OPENSSLBASE}/include/openssl \
		--with-ssl-lib=${OPENSSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/vtun

ALL_TARGET=	vtund

post-install:
	@${INSTALL_DATA} ${WRKSRC}/vtund.conf ${PREFIX}/etc/vtund.conf.example
	@${MKDIR} ${PREFIX}/share/doc/vtund
.for doc in FAQ README README.Setup README.Shaper
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/vtund
.endfor

.include <bsd.port.mk>
