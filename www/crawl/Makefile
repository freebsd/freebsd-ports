# New ports collection makefile for:	crawl
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crawl
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A small, efficient web crawler with advanced features

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}
CONFIGURE_ENV=	LIBS="${LDFLAGS} -lmd"
CFLAGS+=	-D__FUNCTION__='""'

MAN1=	crawl.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/include/db2,${LOCALBASE}/include/db3,g ; \
		s,db2,db3,g' ${WRKSRC}/configure.in
	${CHMOD} u+w ${WRKSRC}/*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
