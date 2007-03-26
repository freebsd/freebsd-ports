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

BUILD_DEPENDS+= v4l_compat>=1.0.20060801:${PORTSDIR}/multimedia/v4l_compat

LIB_DEPENDS=	uclmmbase:${PORTSDIR}/devel/uclmmbase
USE_TK=		yes
USE_TK_BUILD=	yes

USE_AUTOTOOLS=	autoconf:213
USE_X_PREFIX=	yes
CONFIGURE_ARGS= -x-libraries=${X11BASE}/lib \
		-x-includes=${X11BASE}/include \
		-without-ucltcl \
		-with-tcl=${LOCALBASE} \
		-without-ucltk \
		-with-tk=${LOCALBASE}
.ifndef (NO_INET6)
CONFIGURE_ARGS+=-enable-ipv6
.endif
MAN1=		vic.1

post-patch:
	${RM} ${WRKSRC}/md5*

post-install:
	${STRIP_CMD} ${PREFIX}/bin/vic
	${STRIP_CMD} ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
