# New ports collection makefile for:  wmmail
# Date created:        7 Jun 1998
# Whom:                rom
#
# $FreeBSD$
#

PORTNAME=	wmmail
PORTVERSION=	0.64
PORTREVISION=	3
CATEGORIES=	mail windowmaker
MASTER_SITES=	# none
DISTNAME=	WMMail.app-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A little mail notifier for the Window Maker dock

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList

USE_XORG=	xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-PL-libs="-L${LOCALBASE}/lib" \
		--with-PL-incs="-I${LOCALBASE}/include"

post-install:
	@${ECHO} "		"
	@${ECHO} "------------------------------------------------------------------------------"
	@${ECHO} "===> Installing WMMail defaults in ${PREFIX}/GNUstep/Apps/WMMail.app/Defaults"
	@${ECHO} "===> Modify to your config and copy to ~/GNUstep/Defaults/WMMail"
	@${ECHO} "		"
	@${ECHO} "===> Installing README in ${PREFIX}/GNUstep/Apps/WMMail.app"
	@${ECHO} "------------------------------------------------------------------------------"
	@${ECHO} "		"
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/GNUstep/Apps/WMMail.app

.include <bsd.port.mk>
