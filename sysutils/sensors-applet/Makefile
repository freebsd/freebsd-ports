# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sensors-applet
PORTVERSION=	1.6.1
PORTREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GNOME%20Sensors%20Applet%20Version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME applet displaying hardware sensor values

RUN_DEPENDS=	mbmon:${PORTSDIR}/sysutils/xmbmon \
		smartctl:${PORTSDIR}/sysutils/smartmontools

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomepanel libgnomeui
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
DEFINES=	-DMBMON_EXECUTABLE=\\\"${LOCALBASE}/bin/mbmon\\\" \
		-DSMARTCTL_HELPER=\\\"${PREFIX}/libexec/smartctl-helper\\\"
CPPFLAGS+=	-I${LOCALBASE}/include ${DEFINES}
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${CP} -f ${FILESDIR}/mbmon-sensors-interface.* \
		${FILESDIR}/smartctl-sensors-interface.* ${WRKSRC}/src

post-build:
	${CC} ${CFLAGS} -DSMARTCTL=\"${LOCALBASE}/sbin/smartctl\" \
		-o ${WRKSRC}/smartctl-helper ${FILESDIR}/smartctl-helper.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smartctl-helper ${PREFIX}/libexec
	${CHMOD} u+s ${PREFIX}/libexec/smartctl-helper

.include <bsd.port.mk>
