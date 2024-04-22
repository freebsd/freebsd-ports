PORTNAME=	jnettop
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.13 \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Traffic visualizer, similar to nettop
WWW=		https://sourceforge.net/projects/jnettop/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gmake gnome pkgconfig
USE_GNOME=	glib20

LICENSE=	GPLv2

CONFIGURE_ARGS=	--prefix=${PREFIX}

.if defined(WITH_DAG)
post-configure:
	${ECHO_CMD} "#define BSD 1" >> ${WRKSRC}/config.h
.endif

.include <bsd.port.mk>
