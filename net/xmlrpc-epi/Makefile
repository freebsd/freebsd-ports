# New ports collection makefile for:	xmlrpc-epi
# Date created:			19 February 2007
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-epi
PORTVERSION=	0.51
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A general purpose implementation of the xmlrpc specification in C

USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"		\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"
CONFIGURE_ARGS=	--program-transform="s|^|xre-|"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	AUTHORS ChangeLog NEWS README

METHODS=	TestNormal TestFault TestStruct TestArray TestBoolean	\
		TestInt TestString TestDouble TestBase64 TestDateTime

CONFLICTS=	xmlrpc-c-0.*

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
