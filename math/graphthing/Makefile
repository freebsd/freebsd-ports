# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	0.9.2
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool that allows you to create, manipulate and study graphs

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_BISON=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
