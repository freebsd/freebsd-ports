# New ports collection makefile for:	opensaml2
# Date created:				15 September 2008
# Whom:					Janos Mohacsi
#
# $FreeBSD$
#

PORTNAME=	opensaml2
PORTVERSION=	2.4.3
CATEGORIES=	security
MASTER_SITES=	http://www.shibboleth.net/downloads/c++-opensaml/${PORTVERSION}/
DISTNAME=	opensaml-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open source implentation of SAML2

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		log4shib.1:${PORTSDIR}/devel/log4shib \
		xerces-c.28:${PORTSDIR}/textproc/xerces-c2-devel \
		xmltooling.5:${PORTSDIR}/devel/xmltooling

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} \
		--with-xmltooling=${LOCALBASE} --disable-doxygen-doc
USE_GMAKE=	yes
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
