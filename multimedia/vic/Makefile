# New ports collection makefile for:	vic
# Date created:		14 December 1994
# Whom:			wollman
#
# $FreeBSD$
#

PORTNAME=	vic
PORTVERSION=	2.8.1.1.6
CATEGORIES=	mbone tk84 ipv6
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/vic/2.8ucl1.1.6/
DISTNAME=	${PORTNAME}-2.8ucl1.1.6

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	MBONE video tool

LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84 \
		uclmmbase:${PORTSDIR}/devel/uclmmbase

USE_AUTOCONF_VER=	213
USE_X_PREFIX=	yes
CONFIGURE_ARGS= -x-libraries=${PREFIX}/lib \
		-x-includes=${PREFIX}/include \
		-without-ucltcl \
		-with-tcl=${LOCALBASE} \
		-without-ucltk \
		-with-tk=${LOCALBASE} \
		-enable-ipv6
MAN1=		vic.1

post-patch:
	${RM} ${WRKSRC}/md5*

post-install:
	${STRIP_CMD} ${PREFIX}/bin/vic
	${STRIP_CMD} ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
