# ex:ts=8
# Ports collection makefile for:	xmlstartlet
# Date created:			Jun 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlstarlet
PORTVERSION=	0.9.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmlstar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line XML Toolkit

USE_REINPLACE=	yes
USE_ICONV=	yes
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libxml-prefix=${LOCALBASE} \
		--with-libxslt-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -liconv"

PLIST_FILES=	bin/xml
MAN1=	xmlstarlet.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS," \
		-e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
