PORTNAME=	udt
PORTVERSION=	4.11
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	udt.sdk.${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	C++ library containing the UDT API implementation
WWW=		http://udt.sourceforge.net/

PATCH_WRKSRC=	${WRKDIR}/udt${PORTVERSION:R}
WRKSRC=		${PATCH_WRKSRC}/src
MAKEFILE=	${FILESDIR}/BSDmakefile
EXTRACT_AFTER_ARGS=	--exclude '*md5*'	\
		--exclude udt${PORTVERSION:R}/win
USE_LDCONFIG=	yes
UDT_APPS=	appclient appserver recvfile sendfile test
USES=		uidfix

OPTIONS_DEFINE=	DOCS

DOCS_VARS_OFF=	EXTRACT_AFTER_ARGS+="--exclude udt${PORTVERSION:R}/doc"

post-build:
	# Building sample applications:
.for a in ${UDT_APPS}
	${CXX} ${CXXFLAGS} ${WRKSRC:H}/app/$a.cpp -o ${WRKSRC:H}/app/udt-$a \
	    -I${WRKSRC} -L${WRKSRC} -ludt -pthread
.endfor

post-install:
	# Installing sample applications:
	${INSTALL_PROGRAM} ${UDT_APPS:S|^|${WRKSRC:H}/app/udt-|} ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	# Installing documentation tree into ${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC:H}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
