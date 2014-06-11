# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	trickle
PORTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight, portable bandwidth shaper

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--with-libevent=${LOCALBASE} \
		--sysconfdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	*
post-install:
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${STAGEDIR}${PREFIX}/etc/trickled.conf.default
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
