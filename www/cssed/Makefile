# ex:ts=8
# Ports collection makefile for:	cssed
# Date created:			Jul 29, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cssed
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application to help CSS style sheets creation and maintenance

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	cssed.1

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
