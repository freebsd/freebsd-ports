# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	1.12.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}d/${PORTNAME}d-${PORTVERSION}
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LICENSE=	GPLv2

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

ALL_TARGET=	dict
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dict
LIBS+=		-L${LOCALBASE}/lib
USES=		bison gmake libtool:build

post-patch:
	@${REINPLACE_CMD} -e 's|^        mkdir|	mkdir|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/dict.conf ${STAGEDIR}${PREFIX}/etc/dict.conf.sample

.include <bsd.port.mk>
