# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	0.7
CATEGORIES=	math
MASTER_SITES=	http://members.optushome.com.au/davidsymonds/gt/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_BISON=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--without-included-gettext \

.include <bsd.port.mk>
