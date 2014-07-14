# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	opensaml2
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/${PORTVERSION}/
DISTNAME=	opensaml-${PORTVERSION}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Open source implementation of SAML2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		liblog4shib.so:${PORTSDIR}/devel/log4shib \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libxmltooling.so:${PORTSDIR}/devel/xmltooling

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} \
		--with-xmltooling=${LOCALBASE} --disable-doxygen-doc
USES=		gmake pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    ${WRKSRC}/configure

.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
