# New ports collection makefile for:	opensaml
# Date created:				06 Febuary 2007
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	opensaml
DISTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source implentation of SAML

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		log4cpp.4:${PORTSDIR}/devel/log4cpp \
		xml-security-c.14:${PORTSDIR}/security/apache-xml-security-c

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
