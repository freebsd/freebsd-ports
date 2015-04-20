# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libnfs
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/sahlberg/${PORTNAME}/

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Client library for accessing NFS shares over a network

LICENSE=	LGPL21 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pkgconfig
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
