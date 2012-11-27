# Created by: Sean Greven <sean.greven@gmail.com>
# $FreeBSD$

PORTNAME=	fwknop
PORTVERSION=	2.0.3
CATEGORIES=	security
MASTER_SITES=	http://www.cipherdyne.org/fwknop/download/

MAINTAINER=	sean.greven@gmail.com
COMMENT=	SPA implementation for Linux and FreeBSD

OPTIONS_DEFINE=		GPGME
OPTIONS_DEFAULT=	GPGME
GPGME_DESC=	Build support for gpgme
MAN8=		fwknop.8 fwknopd.8
INFO=		libfko
MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
USE_RC_SUBR=	fwknopd
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPGME}
BUILD_DEPENDS+=	gpgme:${PORTSDIR}/security/gpgme
.endif

.include <bsd.port.mk>
