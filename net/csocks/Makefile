# New ports collection makefile for:	csocks
# Date created:				06 August 2007
# Whom:					Raffaele De Lorenzo - raffaele.delorenzo@libero.it
#
# $FreeBSD$
#

PORTNAME=	csocks
PORTVERSION=	1.5
CATEGORIES=	net security
MASTER_SITES=	http://csocks.altervista.org/download/ \
		http://csocks.virtuale.org/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS Client v4/v5 RFC Compliant with many features

PLIST_FILES=	etc/csocks.conf.sample lib/libcsocks.so lib/libcsocks.so.1 bin/csocks

WRKSRC=		${WRKDIR}/src
USE_LDCONFIG=	yes
MAN1=		csocks.1
MAN5=		csocks.conf.5
MANCOMPRESSED=	yes

post-patch:
	${REINPLACE_CMD} "s#/usr/local#${PREFIX}#" ${WRKDIR}/src/Makefile

do-install:
	${CP} -p ${WRKDIR}/src/libcsocks.so.1 ${PREFIX}/lib/
	${LN} -fs ${PREFIX}/lib/libcsocks.so.1 ${PREFIX}/lib/libcsocks.so
	${CP} -p ${WRKDIR}/freebsd/csocks ${PREFIX}/bin
	${CP} -p ${WRKDIR}/csocks.conf ${PREFIX}/etc/csocks.conf.sample
	${CP} -p ${WRKDIR}/man/csocks.1.gz ${MANPREFIX}/man/man1
	${CP} -p ${WRKDIR}/man/csocks.conf.5.gz ${MANPREFIX}/man/man5

.include <bsd.port.mk>
