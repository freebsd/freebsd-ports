# New ports collection makefile for:	pam_p11
# Date created:			1 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_p11
PORTVERSION=	0.1.2
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PAM module using crypto tokens for auth

LIB_DEPENDS=	p11.1:${PORTSDIR}/security/libp11

USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

DOC_FILES=	README *.sh *.xsl *.css *.html

PORTDOCS=	*

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${CP} -R ${DOC_FILES} ${DOCSDIR})
.endif

.include <bsd.port.mk>
