# New ports collection makefile for: timbl
# Date created:		13 March 2008
# Whom:			Yuri Victorovich <yuri@tsoft.com>
#
# $FreeBSD$
#

PORTNAME=	timbl
PORTVERSION=	6.4.2
CATEGORIES=	math
MASTER_SITES=	http://ilk.uvt.nl/downloads/pub/software/

MAINTAINER=	yuri@tsoft.com
COMMENT=	Tilburg Memory Based Learner

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

MAN1=	timbl.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's#doc/@PACKAGE@/examples#examples/@PACKAGE@#' ${WRKSRC}/demos/Makefile.in

.include <bsd.port.mk>
