# New ports collection makefile for:   qalculate
# Date created:        07 July 2004
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	qalculate
PORTVERSION=	0.9.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	asa@agava.com
COMMENT=	Very powerful GUI calculator for GNOME

LIB_DEPENDS=	qalculate.2:${PORTSDIR}/math/libqalculate
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		wget:${PORTSDIR}/ftp/wget

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libglade2 libgnome
INSTALLS_OMF=	yes

.include <bsd.port.mk>
