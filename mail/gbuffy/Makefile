# New ports collection makefile for:	gbuffy
# Date created:		2 October 1999
# Whom:			rasmus@kaj.se
#
# $FreeBSD$
#

PORTNAME=	gbuffy
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/gbuffy/gbuffy-${PORTVERSION}/

MAINTAINER=	olive@oban.frmug.org
COMMENT=	A GTK+ multiple mailbox "biff" program

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		compface.1:${PORTSDIR}/mail/faces

PLIST_FILES=	bin/gbuffy
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
