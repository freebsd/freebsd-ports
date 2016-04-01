# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powerman
PORTVERSION=	2.3.20
PORTREVISION=	2
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://github.com/chaos/powerman/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for doing remote power control

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool perl5 shebangfix
SHEBANG_FILES=	heartbeat/powerman
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httppower --localstatedir=/var \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_RC_SUBR=	powerman

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|:.*|:|' ${WRKSRC}/scripts/Makefile.in

.include <bsd.port.mk>
