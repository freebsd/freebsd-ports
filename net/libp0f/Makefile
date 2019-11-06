# Created by: Eric Allen Griff <setjmp@hotmail.com>
# $FreeBSD$

PORTNAME=	libp0f
PORTVERSION=	2.0.8
CATEGORIES=	net
MASTER_SITES=	http://tools.netsa.cert.org/confluence/download/attachments/16547842/
DISTNAME=	p0flib

MAINTAINER=	setjmp@hotmail.com
COMMENT=	Library of p0f-2.x for yaf as in the CERT NETSA confluence

BROKEN=		unfetchable

LICENSE=	LGPL21

WRKSRC_SUBDIR=	libp0f
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig tar:tgz
USE_LDCONFIG=	yes

post-install:
	${RM} ${STAGEDIR}${LOCALBASE}/bin/p0f
	${MV} ${STAGEDIR}/etc/p0f ${STAGEDIR}${LOCALBASE}/etc/libp0f
	${RM} -r ${STAGEDIR}/etc

.include <bsd.port.mk>
