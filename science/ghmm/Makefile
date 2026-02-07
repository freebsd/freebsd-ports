PORTNAME=	ghmm
DISTVERSION=	0.9-rc3
PORTREVISION=	3
CATEGORIES=	science math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	General Hidden Markov Model Library in C
WWW=		https://ghmm.sourceforge.net/

LICENSE=	GPLv3

USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-python

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	graphviz # bin/cluster

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
