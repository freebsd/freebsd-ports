# ex:ts=8
# Ports collection makefile for:	hashish
# Date Created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hashish
PORTVERSION=	0.4b
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www4.ncsu.edu/~jllovela/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-beta-0.4-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file and string hashing utility

# Apparently out of sync with cryptopp
BROKEN=		"Compile fails: cannot find cryptopp/sapphire.h"

BUILD_DEPENDS=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
LIB_DEPENDS=	wx_gtk:${PORTSDIR}/x11-toolkits/wxgtk-devel

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/Hashish
CFLAGS+=	-I${LOCALBASE}/include
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,^CXXFLAGS =,CXXFLAGS+=${PTHREAD_CFLAGS},g ; \
		s,^LBLIBS =,LBLIBS = ${PTHREAD_LIBS} -L${LOCALBASE}/lib,g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,crypto/,cryptopp/,g" ${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hashish ${PREFIX}/bin

.include <bsd.port.post.mk>
