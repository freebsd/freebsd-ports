# New ports collection makefile for:	wmclockmon
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmclockmon
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A digital clock dockapp with a similar look to wmcpuload

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/wmclockmon

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/wmclockmon-config/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmclockmon ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/wmclockmon.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
