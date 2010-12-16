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
COMMENT=	An SPA implimentation for Linux and FreeBSD

BUILD_DEPENDS=	${SITE_PERL}/Net/IPv4Addr.pm:${PORTSDIR}/net-mgmt/p5-Net-IPv4Addr \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/Net/Pcap.pm:${PORTSDIR}/net/p5-Net-Pcap \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/${PERL_ARCH}/Net/RawIP.pm:${PORTSDIR}/net/p5-Net-RawIP \
		${SITE_PERL}/GnuPG/Key.pm:${PORTSDIR}/security/p5-GnuPG-Interface \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/NetPacket.pm:${PORTSDIR}/net/p5-NetPacket \
		${SITE_PERL}/Net/Ping/External.pm:${PORTSDIR}/net/p5-Net-Ping-External
RUN_DEPENDS=	${BUILD_DEPENDS}

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
