# Ports collection makefile for:	xmlsec1
# Date created:			Apr 17, 2003
# Whom:				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	xmlsec1
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	XML Security Library

LIB_DEPENDS=	xslt:${PORTSDIR}/textproc/libxslt \
		gnutls.8:${PORTSDIR}/security/gnutls

USE_LIBTOOL=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	-build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-gnutls="${LOCALBASE}"

MAN1=	xmlsec1.1 xmlsec1-config.1

post-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s:src apps man docs:src apps man:g" \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
