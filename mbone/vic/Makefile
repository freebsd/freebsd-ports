# New ports collection makefile for:	vic
# Date created:		14 December 1994
# Whom:			wollman
#
# $FreeBSD$
#

PORTNAME=	vic
PORTVERSION=	2.8.1.1.3
CATEGORIES=	mbone tk83
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/vic/2.8ucl-1.1.3/
DISTNAME=	${PORTNAME}-2.8ucl-1.1.3

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
BUILD_DEPENDS=  ${LOCALBASE}/lib/libuclmmbase.a:${PORTSDIR}/devel/uclmmbase

WRKSRC=		${WRKDIR}/vic-2.8ucl-1.1.3/vic

USE_AUTOCONF=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS= -x-libraries=${PREFIX}/lib \
		-x-includes=${PREFIX}/include \
		-without-ucltcl \
		-with-tcl=${LOCALBASE} \
		-without-ucltk \
		-with-tk=${LOCALBASE}
MAN1=		vic.1

pre-patch:
	@${FIND} ${WRKSRC} -name "*.[c,h]" | ${XARGS} ${PERL} -pi -e \
		's|malloc.h|stdlib.h|'

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
