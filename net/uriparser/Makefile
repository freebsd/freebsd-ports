# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uriparser
PORTVERSION=	0.8.4
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	URI parsing library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc --disable-test
INSTALL_TARGET=	install-strip
USES=		libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
