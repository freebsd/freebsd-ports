# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.54.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-base/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose implementation of the xmlrpc specification in C

LICENSE=	MIT

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		gmake iconv libtool:keepla
USE_BZIP2=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform="s|^|xre-|"

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean \
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-0.* xmlrpc-c-devel-[0-9]*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

regression-test:
.for tm in ${METHODS}
	cd ${WRKSRC}/sample && ./sample -method method_${tm}
.endfor

.include <bsd.port.mk>
