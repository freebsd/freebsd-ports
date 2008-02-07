# New ports collection makefile for:	sqlninja
# Date created:				2007-10-17
# Whom:					Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sqlninja
DISTVERSION=	0.2.1-r1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	Sql Server exploit toolkit

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap \
		p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket

USE_PERL5=	yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${ETCDIR}
	${MKDIR} ${ETCDIR}/scripts
	${MKDIR} ${ETCDIR}/dnstun
	${MKDIR} ${DOCSDIR}
.	for i in sqlninja
		${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.	endfor
.	for i in dnstun.scr nc.scr
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/${i} ${ETCDIR}/scripts
.	endfor
.	for i in dnstun.c dnstun.exe
		${INSTALL_SCRIPT} ${WRKSRC}/dnstun/${i} ${ETCDIR}/dnstun
.	endfor
.if !defined(NOPORTDOCS)
.	for i in sqlninja-howto.html sqlninja.conf.example
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.mk>
