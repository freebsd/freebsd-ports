# New ports collection makefile for:	trafd
# Date created:		22 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	trafd
PORTVERSION=	3.0.2.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.riss-telecom.ru/pub/dev/trafd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BPF Traffic Collector

USE_RC_SUBR=	trafd

CONFLICTS=	bpft-4.*

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
	@${MKDIR} ${PREFIX}/var/trafd
	@${MKDIR} ${PREFIX}/var/log
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>
post-patch:
.if	${OSVERSION} >= 800000
	@${REINPLACE_CMD} -e "s|-DCSLIP|-UCSLIP|" \
	    ${WRKSRC}/Makefile.inc
.endif

.include <bsd.port.post.mk>
