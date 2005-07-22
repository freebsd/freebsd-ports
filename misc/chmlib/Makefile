# ex:ts=8
# Ports collection makefile for:	chmlib
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	chmlib
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://66.93.236.84/~jedwin/projects/chmlib/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A library for dealing with Microsoft ITSS/CHM format files

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-io64 --disable-pread
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
