PORTNAME=	libsmi
PORTVERSION=	0.4.8
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/ \
		LOCAL/bms

MAINTAINER=	saper@saper.info
COMMENT=	Library to access SMI MIB information
WWW=		https://www.ibr.cs.tu-bs.de/projects/libsmi/

USES=		cpe gmake libtool pathfix pkgconfig
CPE_VENDOR=	tu-braunschweig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PIBDIR=		${PREFIX}/share/smi/pibs
MIBDIR=		${PREFIX}/share/smi/mibs
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--with-data-dir=${PREFIX}/share/smi \
		--with-pibdir=${PIBDIR} --with-mibdir=${MIBDIR}

.include <bsd.port.mk>
