# New ports collection makefile for:    www6to4
# Date created:         22.03.2002
# Whom: Janos Mohacsi <janos.mohacsi@dante.org.uk>
#
# $FreeBSD$

PORTNAME=	www6to4
PORTVERSION=	1.5
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Lightweight http proxy to help IPv4 only browsers

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
	@if [ ! -f ${PREFIX}/etc/rc.d/www6to4.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/www6to4.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/www6to4.sh ${PREFIX}/etc/rc.d/www6to4.sh; \
	fi

.include <bsd.port.mk>
