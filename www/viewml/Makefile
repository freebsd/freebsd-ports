# Ports collection Makefile for:	viewml
# Date created:				Black Friday (13 April 2001)
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	viewml
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.viewml.com/pub/viewml/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		wwwzip.1:${PORTSDIR}/www/libwww

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_BISON=	yes
CFLAGS+=	-fpermissive -include /usr/include/sys/types.h \
		-DPREFIX=\\\"${PREFIX}\\\"

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKEFILE} ${MAKE_ARGS} depend)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/viewml ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/viewml
	${INSTALL_DATA} ${WRKSRC}/khtmlw_dnd.xpm ${PREFIX}/share/viewml

.include <bsd.port.mk>
