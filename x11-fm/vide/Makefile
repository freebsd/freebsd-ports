# New ports collection makefile for:	vide
# Date created:				May 17 2000
# Whom:					careilly
#
# $FreeBSD$
#

PORTNAME=	vide
PORTVERSION=	0.2.6
CATEGORIES=	x11-fm
MASTER_SITES=	http://vide.sourceforge.net/

MAINTAINER=	careilly@thecia.ie

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-DHAVE_SYS_PARAM_H" \
		GTK_CONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS=	--disable-gtktest

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
