# Created by: Pankov Pavel <pankov_p@mail.ru>
# $FreeBSD$

PORTNAME=	microdc2
PORTVERSION=	0.15.6
PORTREVISION=	8
CATEGORIES=	net-p2p
MASTER_SITES=	http://corsair626.no-ip.org/microdc/

MAINTAINER=	pankov_p@mail.ru
COMMENT=	Command-line based Direct Connect client

LICENSE=	GPLv2

CONFLICTS=	tthsum-[0-9]*

USES=		gnome iconv readline
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
