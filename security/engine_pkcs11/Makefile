# New ports collection makefile for:	engine_pkcs11
# Date created:			1 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engine_pkcs11
PORTVERSION=	0.1.4
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An implementation of a PKCS\#11 engine for OpenSSL

LIB_DEPENDS=	p11.1:${PORTSDIR}/security/libp11

USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

CONFIGURE_ARGS=	--with-openssl="${OPENSSLBASE}"

DOC_FILES=	README *.sh *.xsl *.css *.html

PORTDOCS=	*

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${CP} -R ${DOC_FILES} ${DOCSDIR})
.endif

.include <bsd.port.mk>
