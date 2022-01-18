# Created by: Roman Shterenzon <roman@xpert.com>

PORTNAME=	hping
PORTVERSION=	2.0.0r3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.hping.org/ \
		http://200ok.org/distfiles/hping/
DISTNAME=	hping2.0.0-rc3

MAINTAINER=	ecu@200ok.org
COMMENT=	Network auditing tool

DEPRECATED=	Deprecated upstream, please consider using net/hping3 instead
EXPIRATION_DATE=2022-03-31

CONFLICTS=	hping-devel

WRKSRC=		${WRKDIR}/hping2-rc3

BROKEN_aarch64=	fails to build: cannot find the byte order for this architecture, fix bytesex.h
BROKEN_riscv64=	fails to build: cannot find the byte order for this architecture, fix bytesex.h

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--force-libpcap

PLIST_FILES=	sbin/hping man/man8/hping.8.gz
PORTDOCS=	AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN \
		MORE-FUN-WITH-IPID SPOOFED_SCAN.txt APD.txt

OPTIONS_DEFINE=	DOCS

EXTRA_PATCHES=	${FILESDIR}/extra-patch-sendip.c

post-patch:
	@${REINPLACE_CMD} -e '/^struct ars_layer_info ars_linfo/d' \
		${WRKSRC}/ars.h
	@${REINPLACE_CMD} -e '/^volatile struct delaytable_element/d' \
		${WRKSRC}/hping2.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${STAGEDIR}${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 \
		${STAGEDIR}${MANPREFIX}/man/man8/hping.8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
