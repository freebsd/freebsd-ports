# New ports collection makefile for:	kovpn
# Date created:				13 April 2006
# Whom:					anderson@cnpm.embrapa.br
#
# $FreeBSD$
#

PORTNAME=	kovpn
PORTVERSION=	0.3
CATEGORIES=	security kde
MASTER_SITES=	http://home.bawue.de/~lighter/www.enlighter.de/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}_pre6

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A simple GUI for OpenVPN clients

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes
USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_XPM=	yes

USE_AUTOTOOLS=	libtool:15

post-install:
	${MKDIR} ${PREFIX}/share/doc/kovpn; \
	${CP} ${FILESDIR}/README ${PREFIX}/share/doc/kovpn

.include <bsd.port.mk>
