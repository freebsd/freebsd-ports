# New ports collection makefile for:	gbuffy
# Date created:		2 October 1999
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	gbuffy
PORTVERSION=	0.2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/gbuffy/

MAINTAINER=	kaj@Raditex.se

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		compface.1:${PORTSDIR}/mail/faces

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
