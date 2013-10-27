# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zebra-server
PORTVERSION=	2.0.55
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/zebra/
DISTNAME=	idzebra-${PORTVERSION}

MAINTAINER=	ben@gibbed.org
COMMENT=	Z39.50/SR server software

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libyaz.so:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}/bin \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-iconv=${ICONV_PREFIX} --with-expat=${LOCALBASE}

USES=		iconv
USE_LDCONFIG=	yes
USE_TCL=	yes

.include <bsd.port.mk>
