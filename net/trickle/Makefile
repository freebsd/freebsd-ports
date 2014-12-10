# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	trickle
PORTVERSION=	1.07
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, portable bandwidth shaper

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	DOCS

USES=		libtool
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
