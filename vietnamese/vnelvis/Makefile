# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	vnelvis
PORTVERSION=	1.4
CATEGORIES=	vietnamese editors
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	A vi clone that speaks Vietnamese

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

BUILD_DEPENDS=  ${LOCALBASE}/lib/libviqr.a:${PORTSDIR}/vietnamese/libviet

CFLAGS+=	-I${PREFIX}/include/viet
MAN1=		vnelvis.1 vnvi.1

post-extract:
	@ cd ${WRKSRC} ; make clean
	@ ${MV} ${WRKDIR}/lib ${WRKDIR}/DONT.lib
	@ ${MV} ${WRKDIR}/include ${WRKDIR}/DONT.include

post-install:
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnelvis.1
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnvi.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800039
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
