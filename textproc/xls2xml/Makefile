# New ports collection makefile for:	xls2xml
# Date created:				4 November 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xls2xml
PORTVERSION=	1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://arturo.directmail.org/filters/archive/
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole \
		xml.5:${PORTSDIR}/textproc/libxml

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lcole"

.include <bsd.port.mk>
