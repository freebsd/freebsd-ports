# New ports collection makefile for:	drac
# Date created:			07 January 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	drac
PORTVERSION= 	1.11
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	anders@fix.no

NO_WRKSUBDIR=	yes

MAN3=		dracauth.3
MAN1=		rpc.dracd.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/rpc.dracd.1m
	@${ECHO} "================================================================================"
	@${ECHO} "Use make -DWITH_POSTFIX or -DWITH_EXIM with this port for databases compatible"
	@${ECHO} "with those MTAs."
	@${ECHO} "================================================================================"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rpc.dracd ${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/drac.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/libdrac.a ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/dracauth.3 ${PREFIX}/man/man3/
	@${INSTALL_MAN} ${WRKSRC}/rpc.dracd.1m ${PREFIX}/man/man1/rpc.dracd.1
.endif

.include <bsd.port.mk>
