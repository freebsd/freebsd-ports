# Created by: Janos Mohacsi <janos.mohacsi@dante.org.uk>
# $FreeBSD$

PORTNAME=	www6to4
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Lightweight http proxy to help IPv4 only browsers

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./-/}

USE_RC_SUBR=	www6to4

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' \
		${WRKSRC}/www6to4.c
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/www6to4 ${PREFIX}/sbin
	@if [ ! -d ${PREFIX}/etc/www6to4 ]; then \
		${MKDIR} ${PREFIX}/etc/www6to4; fi
	${INSTALL_DATA} ${WRKSRC}/www6to4.conf \
		${PREFIX}/etc/www6to4/www6to4.conf.sample
	${INSTALL_DATA} ${WRKSRC}/www6to4_forward.conf \
		${PREFIX}/etc/www6to4/www6to4_forward.conf.sample
.if !defined(NOPORTDOCS)
	if [ ! -d ${DOCSDIR} ]; then \
		${MKDIR} ${DOCSDIR}; fi
	${INSTALL_DATA} ${WRKSRC}/README \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
