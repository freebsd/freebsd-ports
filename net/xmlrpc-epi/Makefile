# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.54.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-base/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose implementation of the xmlrpc specification in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake iconv libtool localbase tar:bzip2
USE_LDCONFIG=	yes
LDFLAGS+=	${ICONV_LIB}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform="s|^|xre-|"
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean \
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-[0-9]*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
.for tm in ${METHODS}
	cd ${WRKSRC}/sample && ./sample -method method_${tm}
.endfor

.include <bsd.port.mk>
