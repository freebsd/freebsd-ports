# New ports collection makefile for:	fung-calc
# Date created:				10.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	fung-calc
PORTVERSION=	1.3.2b
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	Advanced graphic calculator

USE_KDELIBS_VER=	3
USE_GL=		yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
