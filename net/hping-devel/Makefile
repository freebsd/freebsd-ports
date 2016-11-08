# $FreeBSD$

PORTNAME=	hping
PORTVERSION=	3.0.20051105
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://www.hping.org/ \
		http://200ok.org/distfiles/hping/
PKGNAMESUFFIX=	-devel
DISTNAME=	hping3-20051105

MAINTAINER=	ecu@200ok.org
COMMENT=	Network auditing tool

LIB_DEPENDS=	libtcl84.so:lang/tcl84

CONFLICTS=	hping-[0-9]*

BROKEN_aarch64=	fails to build: can not find the byte order for this architecture, fix bytesex.h

GNU_CONFIGURE=	yes
USES=		alias gmake

PLIST_FILES=	sbin/hping lib/hping/hpingstdlib.htcl man/man8/hping.8.gz
PORTDOCS=	AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN \
		MORE-FUN-WITH-IPID SPOOFED_SCAN.txt APD.txt \
		API.txt HPING3.txt

PORTEXAMPLES=	README apd.htcl apd2.htcl ciscoios.htcl ciscoios0.htcl \
		cloner.htcl igrp.htcl isn-spectrogram.htcl nat-noise.htcl \
		passivets.htcl ping.htcl raw.htcl show-tcpseq.htcl \
		showled.htcl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100030
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sendip.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${STAGEDIR}${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${STAGEDIR}${PREFIX}/man/man8/hping.8
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/hping
	${INSTALL_DATA} ${WRKSRC}/lib/hpingstdlib.htcl ${STAGEDIR}${PREFIX}/lib/hping/
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTEXAMPLES}
	${REINPLACE_CMD} -e \
	's|hpingstdlib.htcl|${PREFIX}/lib/hping/hpingstdlib.htcl|' \
		${WRKSRC}/lib/${i}
.endfor
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
