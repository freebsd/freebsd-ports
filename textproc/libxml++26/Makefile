# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml++
PORTVERSION=	0.11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/+/plus/g}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s|xml-config|xml2-config|g" ${WRKSRC}/configure
	@${PERL} -pi -e "s|libxml/|libxml2/|g" ${WRKSRC}/xml++.h

.include <bsd.port.mk>
