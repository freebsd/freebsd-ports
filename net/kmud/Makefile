# New ports collection makefile for:	KMud
# Date created:		31 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kmud
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.kmud.de/pub/kmud/
MASTER_SITE_SUBDIR=	games/muds

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

USE_KDEBASE_VER=1
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		QTDIR="${X11BASE}"

pre-patch:
	@${PERL} -pi -e "s|-ldl ||g" ${WRKSRC}/kmud/Makefile.in

.include <bsd.port.mk>
