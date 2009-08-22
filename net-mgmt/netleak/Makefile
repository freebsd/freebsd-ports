# New ports collection makefile for:	netleak
# Date created:				1 Nov 2005
# Whom:					Vaida Bogdan
#
# $FreeBSD$
#

PORTNAME=	netleak
PORTVERSION=	0.1a
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to detect connectivity between network segments

RUN_DEPENDS=	${SITE_PERL}/Net/PcapUtils.pm:${PORTSDIR}/net/p5-Net-PcapUtils \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/NetPacket/Ethernet.pm:${PORTSDIR}/net/p5-NetPacket \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/${PERL_ARCH}/Net/RawIP.pm:${PORTSDIR}/net/p5-Net-RawIP \
		${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface \
		p5-NetAddr-IP>0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5_RUN=	yes
MAN8=		netleak.8 netleakd.8

PLIST_FILES=	etc/netleak.conf etc/netleakd.conf sbin/netleak sbin/netleakd
PORTDOCS=	BUGS README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
