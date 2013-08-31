# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	libp11
PORTVERSION=	0.2.8
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Small layer on top of PKCS\#11 API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libltdl libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	ltverhack
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

.ifndef(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
.ifndef(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA install-dist_docDATA|install-data-am: install-dist_docDATA|' \
		${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
