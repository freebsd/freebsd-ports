# New ports collection makefile for:	trafd
# Date created:		22 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	trafd
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.riss-telecom.ru/pub/dev/trafd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The BPF Traffic Collector

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafd/trafd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/trafd/trafstart ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/trafd/trafstop ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/trafd/trafsave ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/trafd/trafdump ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trafstat/trafstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trafstatd/trafstatd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/traflog/traflog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/traflog/traflog.format ${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${MKDIR} ${PREFIX}/var/trafd
	${MKDIR} ${PREFIX}/var/log
.include <bsd.port.mk>
