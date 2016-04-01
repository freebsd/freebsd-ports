# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	10
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:graphics/gd

SUB_FILES=	bandwidthd

USE_CSTD=	gnu89

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	ac_cv_lib_iconv_libiconv_open=no \
		ac_cv_lib_m_pow=no \
		ac_cv_lib_png_png_read_info=no \
		ac_cv_lib_pq_PQconnectdb=no
USES=		gmake tar:tgz

post-patch:
	${REINPLACE_CMD} -e '/requires.*libpng/,/exit/d' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bandwidthd \
	    ${STAGEDIR}${PREFIX}/etc/rc.d
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
