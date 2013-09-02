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

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		log4shib.1:${PORTSDIR}/devel/log4shib \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		xmltooling.6:${PORTSDIR}/devel/xmltooling

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} \
		--with-xmltooling=${LOCALBASE} --disable-doxygen-doc
USES=		gmake pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    ${WRKSRC}/configure

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
