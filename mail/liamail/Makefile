# ex:ts=8
# Ports collection makefile for:	liamail
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liamail
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@freebsd.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt" \
		QTDIR="${X11BASE}"
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/qt.so/qt2.so/g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/-lqt/-lqt2/g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
