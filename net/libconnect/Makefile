# Ports collection makefile for:  libconnect
# Date created:                   Sat Mar 29 2003
# Whom:                           Alex Semenyaka <alexs@snark.ratmir.ru>
#
# $FreeBSD$
#

PORTNAME=	libconnect
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/	\
		ftp://ftp.lucky.net/pub/unix/local/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Tell programs to which IP-address they should bind

.if defined(NOPROFILE)
PLIST_SUB+=	NOPROFILE="@comment "
.else
PLIST_SUB+=	NOPROFILE=""
.endif

do-install:
	-@${MKDIR} ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/libconnect.a ${PREFIX}/lib
.if !defined(NOPROFILE)
	@${INSTALL_PROGRAM} ${WRKSRC}/libconnect_p.a ${PREFIX}/lib
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/libconnect.so.1 ${PREFIX}/lib
	@${LN} -fs libconnect.so.1 ${PREFIX}/lib/libconnect.so
	-@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}

.include <bsd.port.mk>
