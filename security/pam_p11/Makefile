# New ports collection makefile for:	pam_p11
# Date created:			1 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_p11
PORTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PAM module using crypto tokens for auth

LIB_DEPENDS=	p11.3:${PORTSDIR}/security/libp11

USE_AUTOTOOLS=	libtool:22
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/wiki
	@(cd ${WRKSRC} && ${CP} NEWS ${DOCSDIR})
	@(cd ${WRKSRC}/doc && ${CP} README ${DOCSDIR})
	@(cd ${WRKSRC}/doc && ${CP} *.css *.html ${DOCSDIR}/wiki)
.endif

.include <bsd.port.mk>
