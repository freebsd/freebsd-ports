# Ports collection makefile for:	xmlsec1
# Date created:			Apr 17, 2003
# Whom:				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	xmlsec1
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	XML Security Library

RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_OPENSSL=	yes
USE_GNOME=	gnomehack libxslt
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=	xmlsec1.1 xmlsec1-config.1

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-gnutls="${LOCALBASE}"
LIB_DEPENDS+=		gnutls.8:${PORTSDIR}/security/gnutls
PLIST_SUB+=             GNUTLS=""
.else
CONFIGURE_ARGS+=	--without-gnutls
PLIST_SUB+=             GNUTLS="@comment "
.endif

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOCS=docs
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_GNUTLS=yes   Enable GNUTLS support"
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's|src apps man docs|src apps man \$${DOCS}|g ; \
		 s|^confexecdir =.*$$|confexecdir = \$$(sysconfdir)|g' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
