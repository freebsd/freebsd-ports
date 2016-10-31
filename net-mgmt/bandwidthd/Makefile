# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	11
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LICENSE=	GPLv3+ # "any version of the GPL that is current as of your download"

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		gmake tar:tgz
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	ac_cv_lib_iconv_libiconv_open=no \
		ac_cv_lib_m_pow=no \
		ac_cv_lib_png_png_read_info=no \
		ac_cv_lib_pq_PQconnectdb=no
USE_CSTD=	gnu89

SUB_FILES=	bandwidthd

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/requires.*libpng/,/exit/d' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bandwidthd \
		${STAGEDIR}${PREFIX}/etc/rc.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
