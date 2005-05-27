# New ports collection makefile for:	wmclockmon
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmclockmon
PORTVERSION=	0.8.1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A digital clock dockapp with a similar look to wmcpuload

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		wmclockmon.1 wmclockmon-config.1 wmclockmon-cal.1

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/wmclockmon-config/Makefile.in

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for i in 1 2
	@${INSTALL_DATA} ${WRKSRC}/doc/sample${i}.wmclockmonrc ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
