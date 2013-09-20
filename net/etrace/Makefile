# Created by: dave.ryan@gmail.com
# $FreeBSD$

PORTNAME=	etrace
PORTVERSION=	1.1
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.bindshell.net/tools/etrace/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dave.ryan@gmail.com
COMMENT=	A configurable static port network tracing tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap

WRKSRC=		${WRKDIR}/etrace
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--with-libdnet=${PREFIX}

MAN8=	etrace.8

NO_STAGE=	yes
.include <bsd.port.mk>
