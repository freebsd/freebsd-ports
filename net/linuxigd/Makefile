# New ports collection makefile for:	linuxigd
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	linuxigd
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-igd
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Linux UPnP Internet Gateway Device

LIB_DEPENDS=	upnp.1:${PORTSDIR}/devel/upnp

USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/linux-igd
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/gateway.h

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
