# New ports collection makefile for:	wmmaiload
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmmaiload
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Incoming mail monitor dockapp with a similar look to wmcpuload

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/wmmaiload

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/wmmaiload-config/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmmaiload ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/wmmaiload.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
