# New ports collection makefile for:	csocks
# Date created:				06 August 2007
# Whom:					Raffaele De Lorenzo - raffaele.delorenzo@libero.it
# $FreeBSD$

PORTNAME=	csocks
PORTVERSION=	1.0
CATEGORIES=	net security
MASTER_SITES=	http://csocks.virtuale.org/download/ \
		http://csocks.altervista.org/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS Client v4/v5 RFC Compliant with many features

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	etc/csocks.conf lib/libcsocks.so lib/libcsocks.so.1 bin/csocks

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LDCONFIG=	yes
MAN1=		csocks.1
MAN5=		csocks.conf.5
MANCOMPRESSED=	yes

do-install:
	${CP} -p ${WRKDIR}/${DISTNAME}/freebsd/libcsocks.so.1 ${PREFIX}/lib/
	${LN} -fs ${PREFIX}/lib/libcsocks.so.1 ${PREFIX}/lib/libcsocks.so
	${CP} -p ${WRKDIR}/${DISTNAME}/freebsd/csocks ${PREFIX}/bin
	${CP} -p ${WRKDIR}/${DISTNAME}/freebsd/csocks.conf ${PREFIX}/etc/
	${CP} -p ${WRKDIR}/${DISTNAME}/man/csocks.1.gz ${MANPREFIX}/man/man1
	${CP} -p ${WRKDIR}/${DISTNAME}/man/csocks.conf.5.gz ${MANPREFIX}/man/man5
.include <bsd.port.mk>
