# Created by: Peter Lai <cowbert@gmail.com>
# $FreeBSD$

PORTNAME=	mod_rivet
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	www tcl
MASTER_SITES=	APACHE/tcl/rivet
DISTNAME=	rivet-${PORTVERSION}

MAINTAINER=	jeff.lawson@flightaware.com
COMMENT=	Embeds a Tcl interpreter in the Apache server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libitcl.so:lang/itcl

USE_APACHE=	22+
USE_LDCONFIG=	${PREFIX}/lib/rivet
USES+=		gmake libtool tcl:85+,tea

INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--with-apxs=${APXS} \
		--with-rivet-target-dir=${PREFIX}/lib/rivet

post-patch:
	@${REINPLACE_CMD} -e 's|`$${apxs_found} -q LIBEXECDIR`|${PREFIX}/${APACHEMODDIR}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
