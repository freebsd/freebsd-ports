# Created by: Corey Smith
# $FreeBSD$

PORTNAME=	pynids
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://jon.oberheide.org/pynids/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	corsmith@gmail.com
COMMENT=	Python interface to libnids

PATCH_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

USES=		pkgconfig
USE_GNOME=	glib20
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/nidsmodule.so

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.pre.mk>

.if exists(${LIBNET_CONFIG})
LIBNET_CFLAGS!=	${LIBNET_CONFIG} --cflags
LIBNET_LIBS!=	${LIBNET_CONFIG} --libs
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} xzf libnids-1.24.tar.gz

post-patch:
	@${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	@${CHMOD} a+rx ${WRKSRC}/config.guess
	@${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	@${CHMOD} a+rx ${WRKSRC}/config.sub
	@${REINPLACE_CMD} -e \
		"s|/usr/local/include|${PREFIX}/include', '${LIBNET_CFLAGS:S/-I//}|; \
		 s|/usr/local/lib|${PREFIX}/lib', '${LIBNET_LIBS:N-l*:S/-L//}|" \
		 ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -Ee \
		's|(LNET_CFLAGS=).*|\1"`${LIBNET_CONFIG} --defines` ${LIBNET_CFLAGS}"|; \
		 s|(LNETLIB=).*|\1"${LIBNET_LIBS} -L${LOCALBASE}/lib"|; \
		 s|gcc|${CC}|' \
		 ${WRKSRC}/libnids-1.24/configure

.include <bsd.port.post.mk>
