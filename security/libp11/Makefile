# New ports collection makefile for:	libp11
# Date created:			1 Jun 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libp11
PORTVERSION=	0.2.3
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A small layer on top of PKCS\#11 API

USE_AUTOTOOLS=	libltdl:15
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

DOC_FILES=	README *.sh *.xsl *.css *.html api

PORTDOCS=	*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/* ${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${CP} -R ${DOC_FILES} ${DOCSDIR})
.endif

.include <bsd.port.mk>
