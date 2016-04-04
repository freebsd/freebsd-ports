# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	trickle
PORTVERSION=	1.07
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, portable bandwidth shaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent2

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--with-libevent=${LOCALBASE} \
		--sysconfdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/trickle/trickle-overload.so
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${STAGEDIR}${PREFIX}/etc/trickled.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
