# New ports collection makefile for:	hotwayd
# Date created:				29 October 2002
# Whom:					John Nielsen <john@jnielsen.net>
#
# $FreeBSD$
#

PORTNAME=	hotwayd
PORTVERSION=	0.51
CATEGORIES=	mail
#MASTER_SITES=	http://people.freenet.de/courierdave/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hotwayd
DISTNAME=	hotway-0.51

MAINTAINER=	john@jnielsen.net

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
