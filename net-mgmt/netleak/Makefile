# New ports collection makefile for:	netleak
# Date created:				1 Nov 2005
# Whom:					Vaida Bogdan
#
# $FreeBSD$
#

PORTNAME=	netleak
PORTVERSION=	0.1a
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to detect connectivity between network segments

RUN_DEPENDS=	p5-Net-PcapUtils>=0:${PORTSDIR}/net/p5-Net-PcapUtils \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket \
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP \
		p5-IO-Interface>=0:${PORTSDIR}/net/p5-IO-Interface \
		p5-NetAddr-IP>0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	run
MAN8=		netleak.8 netleakd.8

PLIST_FILES=	etc/netleak.conf etc/netleakd.conf sbin/netleak sbin/netleakd
PORTDOCS=	BUGS README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
