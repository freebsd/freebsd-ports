# New ports collection makefile for:	crawl
# Date created:				20 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crawl
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A small, efficient web crawler with advanced features

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE} --program-transform-name=''

MAN1=	crawl.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600022
BROKEN=		"Does not compile on FreeBSD >= 6.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/include/db2,${LOCALBASE}/include/db3,g' \
		-e 's,db2,db3,g' ${WRKSRC}/configure.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
