# New ports collection makefile for:	udt
# Date created:				24 January 2012
# Whom:					Mikhail Teterin
#
# $FreeBSD$

PORTNAME=	udt
PORTVERSION=	4.10
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	udt.sdk.${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	C++ library containing the UDT API implementation

PATCH_WRKSRC=	${WRKDIR}/udt${PORTVERSION:R}
WRKSRC=	${PATCH_WRKSRC}/src
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes
EXTRACT_AFTER_ARGS=	|${TAR} -xpf - --exclude '*md5*'	\
		--exclude udt${PORTVERSION:R}/win
USE_LDCONFIG=	yes
UDT_APPS=	appclient appserver recvfile sendfile test

post-build:
	# Building sample applications:
.for a in ${UDT_APPS}
	${CXX} ${CXXFLAGS} ${WRKSRC:H}/app/$a.cpp -o ${WRKSRC:H}/app/udt-$a \
	    -I${WRKSRC} -L${WRKSRC} -ludt
.endfor

post-install:
	# Installing sample applications:
	${INSTALL_PROGRAM} ${UDT_APPS:S|^|${WRKSRC:H}/app/udt-|} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	# Installing documentation tree into ${DOCSDIR}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC:H}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.else
EXTRACT_AFTER_ARGS+=	--exclude udt${PORTVERSION:R}/doc
.endif

.include <bsd.port.mk>
