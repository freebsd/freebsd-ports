# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}d/${PORTNAME}d-${PORTVERSION}
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmaa.so:devel/libmaa

ALL_TARGET=	dict
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dict
USES=		bison gmake libtool:build localbase

post-patch:
	@${REINPLACE_CMD} -e 's|^        mkdir|	mkdir|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/dict.conf ${STAGEDIR}${PREFIX}/etc/dict.conf.sample

.include <bsd.port.mk>
