# ex:ts=8
# New ports collection makefile for:	gxmlviewer
# Date created:			Nov 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gxmlviewer
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xmlviewer with a netscape plugin, and now a bonobo control as well

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs bonobo gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|intl||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
