# Created by: dave.ryan@gmail.com
# $FreeBSD$

PORTNAME=	etrace
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.bindshell.net/tools/etrace/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dave.ryan@gmail.com
COMMENT=	Configurable static port network tracing tool

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:net/libdnet \
		${LOCALBASE}/lib/libpcap.a:net/libpcap

USES=		tar:tgz
WRKSRC=		${WRKDIR}/etrace
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdnet=${PREFIX}

.include <bsd.port.mk>
