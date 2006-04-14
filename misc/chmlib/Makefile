# ex:ts=8
# Ports collection makefile for:	chmlib
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	chmlib
PORTVERSION=	0.37.4
CATEGORIES=	misc
MASTER_SITES=	http://66.93.236.84/~jedwin/projects/chmlib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for dealing with Microsoft ITSS/CHM format files

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-io64 --disable-pread --exec-prefix=${PREFIX}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.37

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
