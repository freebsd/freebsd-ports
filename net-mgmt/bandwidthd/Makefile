# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LICENSE=	GPLv2

LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd

USE_CSTD=	gnu89

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	ac_cv_lib_iconv_libiconv_open=no
USES=		gmake tar:tgz

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
	    ${STAGEDIR}${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
