# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.54.2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-base/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose implementation of the xmlrpc specification in C

LICENSE=	MIT

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USES=		iconv
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--program-transform="s|^|xre-|"

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean \
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-0.* xmlrpc-c-devel-[0-9]*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

regression-test:
.for tm in ${METHODS}
	cd ${WRKSRC}/sample && ./sample -method method_${tm}
.endfor

.include <bsd.port.mk>
