# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#

PORTNAME=	seahorse
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	asa@gascom.ru

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	gpgme.9:${PORTSDIR}/security/gpgme \
		gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		glade-2.0.0:${PORTSDIR}/devel/libglade2

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${CP} ${WRKSRC}/data/seahorse.desktop.in ${WRKSRC}/data/seahorse.desktop
	@${CP} ${WRKSRC}/data/seahorse.schemas.in ${WRKSRC}/data/seahorse.schemas

.include <bsd.port.mk>
