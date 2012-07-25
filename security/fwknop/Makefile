# New ports collection makefile for:	fwknop
#
# Date created:				23 Nov 2007
# Whom:					Sean Greven<sean.greven@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fwknop
PORTVERSION=	1.8.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.cipherdyne.org/fwknop/download/

MAINTAINER=	sean.greven@gmail.com
COMMENT=	SPA implementation for Linux and FreeBSD

BUILD_DEPENDS=	p5-Net-IPv4Addr>=0:${PORTSDIR}/net-mgmt/p5-Net-IPv4Addr \
		p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-Net-RawIP>=0:${PORTSDIR}/net/p5-Net-RawIP \
		p5-GnuPG-Interface>=0:${PORTSDIR}/security/p5-GnuPG-Interface \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket \
		p5-Net-Ping-External>=0:${PORTSDIR}/net/p5-Net-Ping-External
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN8=		fwknop.8 fwknopd.8 knopmd.8 knopwatchd.8
MANCOMPRESSED=	yes

NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5_BUILD=yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/access.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknop
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknop.8
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknop.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknop_serv
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknopd
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/fwknopd.8
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/install.pl
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopmd.8
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopmd.c
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopmd.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopspoof
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knoptm
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopwatchd.8
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/knopwatchd.c
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/init-scripts/fwknop-init.freebsd

do-install:
	cd ${WRKSRC} && ./install.pl
	@${ECHO_MSG} "Configuration files in ${LOCALBASE}/etc/fwknop";

.include <bsd.port.mk>
