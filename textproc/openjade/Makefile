# New ports collection makefile for:	jade
# Version required:	1.2
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

DISTNAME=	jade-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

PATCH_SITES=	http://ftp.debian.org/debian/dists/unstable/main/source/text/
PATCHFILES=	jade_1.2.1-13.diff.gz

MAINTAINER=	jfieber@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		nsgmls coredumps in static constructors
.endif

PATCH_DIST_STRIP?=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	strip ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${MKDIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${PREFIX}/share/doc/jade
	${MKDIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m $(PREFIX)/lib

.include <bsd.port.mk>
