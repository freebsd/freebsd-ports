# Created by: Sean Greven <sean.greven@gmail.com>
# $FreeBSD$

PORTNAME=	fwknop
PORTVERSION=	2.6.7
CATEGORIES=	security
MASTER_SITES=	http://www.cipherdyne.org/fwknop/download/

MAINTAINER=	sean.greven@gmail.com
COMMENT=	SPA implementation for Linux and FreeBSD

LICENSE=	GPLv2

CPE_VENDOR=	cipherdyne

OPTIONS_DEFINE=		GPGME
OPTIONS_DEFAULT=	GPGME

GPGME_DESC=	Build support for gpgme

USES=		cpe libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	fwknopd

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
INFO=		libfko

GPGME_LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme
GPGME_CONFIGURE_WITH=	gpgme

.include <bsd.port.mk>
