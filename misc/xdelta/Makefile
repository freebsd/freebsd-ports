# New ports collection makefile for:		xdelta
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	1.1.2
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	c9710216@atlas.newcastle.edu.au

USE_GLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=		xdelta.1

pre-patch:
	@${PERL} -pi -e 's|\$\(top_builddir\)/libtool|\$\(prefix\)/bin/libtool|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
