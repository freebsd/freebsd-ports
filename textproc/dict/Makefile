# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	1.13.0
CATEGORIES=	textproc
MASTER_SITES=	SF/dict/dictd/dictd-${PORTVERSION}
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmaa.so:devel/libmaa

USES=		bison gmake libtool:build localbase

ALL_TARGET=	dict
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dict

post-install:
	${INSTALL_DATA} ${FILESDIR}/dict.conf ${STAGEDIR}${PREFIX}/etc/dict.conf.sample

.include <bsd.port.mk>
