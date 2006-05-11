# New ports collection makefile for:	hping-devel
# Date Created:				2005/10/31
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$

PORTNAME=	hping
PORTVERSION=	3.0.20051105
CATEGORIES=	net security
MASTER_SITES=	http://www.hping.org/ \
		http://ipv42.net/distfiles/hping/
PKGNAMESUFFIX=	-devel
DISTNAME=	hping3-20051105

MAINTAINER=	ecu@ipv42.net
COMMENT=	Network auditing tool

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84

NO_LATEST_LINK=	yes
CONFLICTS=	hping-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_DIRS+=	lib/hping
PLIST_FILES=	sbin/hping lib/hping/hpingstdlib.htcl
PORTDOCS=	AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN \
		MORE-FUN-WITH-IPID SPOOFED_SCAN.txt APD.txt \
		API.txt HPING3.txt
MAN8=		hping.8

EXAMPLES=	README apd.htcl apd2.htcl ciscoios.htcl ciscoios0.htcl \
		cloner.htcl igrp.htcl isn-spectrogram.htcl nat-noise.htcl \
		passivets.htcl ping.htcl raw.htcl show-tcpseq.htcl \
		showled.htcl

.if !defined(NOPORTDOCS)
PLIST_DIRS+=	%%EXAMPLESDIR%%
.for file in ${EXAMPLES}
PLIST_FILES+=	%%EXAMPLESDIR%%/${file}
.endfor
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${PREFIX}/man/man8/hping.8
	${MKDIR} ${PREFIX}/lib/hping
	${INSTALL_DATA} ${WRKSRC}/lib/hpingstdlib.htcl ${PREFIX}/lib/hping/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.for i in ${EXAMPLES}
	${REINPLACE_CMD} -e \
	's|hpingstdlib.htcl|${PREFIX}/lib/hping/hpingstdlib.htcl|' \
		${WRKSRC}/lib/${i}
.endfor
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/lib/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
