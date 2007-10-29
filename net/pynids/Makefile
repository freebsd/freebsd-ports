# New ports collection makefile for:   pynids
# Date created:                22 Jun 2005
# Whom:                        Corey Smith
#
# $FreeBSD$
#

PORTNAME=	pynids
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://pilcrow.madison.wi.us/pynids/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pynids-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	corsmith@gmail.com
COMMENT=	Python interface to libnids

PATCH_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10
BUILD_DEPENDS:=	${PATCH_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

CFLAGS+=	-fPIC

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/nidsmodule.so

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

.include <bsd.port.pre.mk>

.if exists(${LIBNET_CONFIG})
LIBNET_CFLAGS!=	${LIBNET_CONFIG} --cflags
LIBNET_LIBS!=	${LIBNET_CONFIG} --libs
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} xf libnids-1.19.tar

post-patch:
	${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	${CHMOD} a+rx ${WRKSRC}/config.guess
	${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	${CHMOD} a+rx ${WRKSRC}/config.sub
	@${REINPLACE_CMD} -e \
		's|/usr/local/include|${LIBNET_CFLAGS:S/-I//}|; \
		 s|/usr/local/lib|${LIBNET_LIBS:N-l*:S/-L//}|' \
		 ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -Ee \
		's|(LNET_CFLAGS=).*|\1"`${LIBNET_CONFIG} --defines` ${LIBNET_CFLAGS}"|; \
		 s|(LNETLIB=).*|\1"${LIBNET_LIBS}"|; \
		 s|gcc|${CC}|' \
		 ${WRKSRC}/libnids-1.19/configure

.include <bsd.port.post.mk>
