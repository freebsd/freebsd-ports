# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	9
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LICENSE=	GPLv2

LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd \
		libpng16.so:${PORTSDIR}/graphics/png

SUB_FILES=	bandwidthd

USE_CSTD=	gnu89

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	ac_cv_lib_iconv_libiconv_open=no \
		ac_cv_lib_pq_PQconnectdb=no
USES=		gmake tar:tgz

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bandwidthd \
	    ${STAGEDIR}${PREFIX}/etc/rc.d
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
