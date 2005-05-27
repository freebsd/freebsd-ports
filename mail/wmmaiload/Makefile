# New ports collection makefile for:	wmmaiload
# Date created:				Sat Sep 21 01:48:10 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmmaiload
PORTVERSION=	1.0.3
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

MAN1=		${PORTNAME}.1 ${PORTNAME}-config.1
PLIST_FILES=	bin/wmmaiload bin/wmmaiload-config
PLIST_DIRS=	share/nls/POSIX share/nls/en_US.US-ASCII

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/wmmaiload-config/Makefile.in

.include <bsd.port.mk>
