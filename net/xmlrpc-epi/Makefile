# New ports collection makefile for:	xmlrpc-epi
# Date created:			19 February 2007
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.54
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose implementation of the xmlrpc specification in C

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"		\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"
CONFIGURE_ARGS=	--program-transform="s|^|xre-|" \
		--with-expat=/usr/local

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean	\
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-0.* xmlrpc-c-devel-[0-9]*

pre-configure:
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS}	\
	${REINPLACE_CMD} -e '/^LTCOMPILE =/s/--mode=/--tag=CC --mode=/'
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS}	\
	${REINPLACE_CMD} -e '/^LINK =/s/--mode=/--tag=CC --mode=/'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

regression-test:
.for tm in ${METHODS}
	cd ${WRKSRC}/sample &&	\
	./sample -method method_${tm}
.endfor

.include <bsd.port.mk>
