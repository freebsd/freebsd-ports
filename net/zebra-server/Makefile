# Created by: Dmitry Sivachenko <demon@FreeBSD.org>

PORTNAME=	zebra-server
PORTVERSION=	2.0.55
PORTREVISION=	16
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/zebra/
DISTNAME=	idzebra-${PORTVERSION}

MAINTAINER=	ben@gibbed.org
COMMENT=	Z39.50/SR server software

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libicui18n.so:devel/icu \
		libyaz.so:net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}/bin \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-iconv=${ICONV_PREFIX} --with-expat=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		iconv libtool shebangfix tcl
SHEBANG_FILES=	util/idzebra-abs2dom
USE_LDCONFIG=	yes

.include <bsd.port.mk>
