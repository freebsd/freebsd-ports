# ex:ts=8
# Ports collection makefile for:	xmlstartlet
# Date created:			Jun 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlstarlet
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	xmlstar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line XML Toolkit

USE_GNOME=	libxslt
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libxml-prefix=${LOCALBASE} \
		--with-libxslt-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

MAN1=		xmlstarlet.1
PLIST_FILES=	bin/xml

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD%%|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
