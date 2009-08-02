# New ports collection makefile for:	lineak-kdeplugins
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak-kdeplugins
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lineak
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE plugins for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix=''

MAN1=		lineak_kdeplugins.1
#MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
