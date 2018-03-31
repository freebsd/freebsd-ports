# Created by: Bob Eager <bob@eager.cx>
# $FreeBSD$

PORTNAME=	regmath
PORTVERSION=	1.00
CATEGORIES=	math
MASTER_SITES=	http://home.interlog.com/~ptjm/ \
		http://www.ancientgeek.org.uk/distfiles/
PKGNAMEPREFIX=	rexx-
DISTNAME=	regmath${PORTVERSION:S/.//}

MAINTAINER=	bob@eager.cx
COMMENT=	Two mathematics libraries for Rexx

LICENSE=	MPL10

BUILD_DEPENDS=	${LOCALBASE}/include/rexxsaa.h:lang/rexx-regina

USES=		zip

CFLAGS+=	-Wno-incompatible-pointer-types

WRKSRC=		${WRKDIR}/math
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
MAKEFILE=	Makefile.bsd

PLIST_FILES=	lib/librexxmath.so lib/librxmath.so man/man1/regmath.1.gz

SUB_FILES=	regmath.1 README testrxmath testrexxmath

PORTDOCS=	regmath.pdf
PORTEXAMPLES=	README testrxmath testrexxmath

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
		${INSTALL_LIB} ${WRKSRC}/librexxmath.so ${STAGEDIR}${PREFIX}/lib/
		${INSTALL_LIB} ${WRKSRC}/librxmath.so ${STAGEDIR}${PREFIX}/lib/
		${INSTALL_MAN} ${WRKDIR}/regmath.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-DOCS-on:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/regmath.pdf ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
		@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKDIR}/README ${STAGEDIR}${EXAMPLESDIR}/
		${INSTALL_DATA} ${WRKDIR}/testrxmath ${STAGEDIR}${EXAMPLESDIR}/
		${INSTALL_DATA} ${WRKDIR}/testrexxmath ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
