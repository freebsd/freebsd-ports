# $FreeBSD$

PORTNAME=	libssm
DISTVERSION=	1.4
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.ccp4.ac.uk/opensource/
DISTNAME=	ssm-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ toolkit for superposition of macromolecules

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libccp4c.so:science/libccp4 \
		libmmdb2.so:science/mmdb2

USES=		gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --enable-ccp4 --with-mmdb=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC
FFLAGS+=	-fPIC

xpost-configure:
	${REINPLACE_CMD} -e 's| -Wl,--as-needed||; s| -Wl,--no-as-needed||' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^archive_cmds=|wl="-Wl,"; archive_cmds=|' ${WRKSRC}/libtool # wl is missing otherwise for some reason

.include <bsd.port.mk>
