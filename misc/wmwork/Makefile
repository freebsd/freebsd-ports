# New ports collection makefile for:	wmwork
# Date created:			16 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmwork
PORTVERSION=	0.2.1
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmwork/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A dockapp that keeps track of time you\'ve spent working on something

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lgnugetopt"

MAN1=	wmwork.1

.include <bsd.port.mk>
