# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	rubiks
PORTVERSION=	20070912
CATEGORIES=	math games
MASTER_SITES=	http://www.cecm.sfu.ca/sage/spkg/upstream/rubiks/		\
		https://mirrors.xmission.com/sage/spkg/upstream/rubiks/		\
		https://www-ftp.lip6.fr/pub/math/sagemath/spkg/upstream/rubiks/ \
		ftp://www-ftp.lip6.fr/pub/math/sagemath/spkg/upstream/rubiks/	 \
		https://mirrors.mit.edu/sage/spkg/upstream/rubiks/		\
		http://files.sagemath.org/spkg/upstream/rubiks/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Several programs for working with Rubik's cubes

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		dos2unix tar:bz2
DOS2UNIX_GLOB=	*.c *.cpp *.h *.txt Makefile

CFLAGS+=		-DLARGE_MEM -DVERBOSE
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

pre-configure:
	${FIND} ${WRKSRC} -iname makefile | ${XARGS} ${REINPLACE_CMD}	\
		-e 's|PREFIX=|#PREFIX=|;s|^CC=|#CC=|;s|^CPP=.*|CPP=${CXX}|;	\
		s|^LINK=.*|LINK=${CXX}|;s|^CFLAGS|#CFLAGS|;s|^LFLAGS=|#LFLAGS=|'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/size222

.include <bsd.port.mk>
