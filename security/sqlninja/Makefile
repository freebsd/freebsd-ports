# New ports collection makefile for:	sqlninja
# Date created:				2007-10-17
# Whom:					Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sqlninja
DISTVERSION=	0.2.5
CATEGORIES=	security
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sql Server exploit toolkit

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap \
		p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket

LICENSE=	GPLv2

USE_PERL5=	yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${ETCDIR}
	${MKDIR} ${ETCDIR}/scripts
	${MKDIR} ${ETCDIR}/apps
.	for i in sqlninja
		${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.	endfor
.	for i in churrasco.scr dnstun.scr nc.scr
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/${i} ${ETCDIR}/scripts
.	endfor
.	for i in churrasco.exe dnstun.exe nc.exe
		${INSTALL_SCRIPT} ${WRKSRC}/apps/${i} ${ETCDIR}/apps
.	endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for i in sqlninja-howto.html sqlninja.conf
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.mk>
