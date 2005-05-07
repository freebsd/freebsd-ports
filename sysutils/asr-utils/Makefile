# ex:ts=8
# Ports collection makefile for:  asr-utils
# Date created:			  Sun Feb 16, 2003
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	asr-utils
PORTVERSION=	3.04
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/u160raid/unix/ \
		ftp://ftp.adaptec.com/raid/u160raid/unix/
DISTNAME=	u160raid_sm_v304_fbsd411
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Adaptec ASR RAID Management Software

BROKEN=		Incomplete pkg-plist

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
BINS=		dptcom dpteng dptscom dptsig raidutil dptmgr

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${FILESDIR}/dptmgr.sh.in > ${WRKDIR}/dptmgr.sh

do-install:
	${MKDIR} ${PREFIX}/dpt
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} ${BINS} ${PREFIX}/dpt
.for bin in ${BINS:Ndptmgr}
	${LN} -sf ${PREFIX}/dpt/${bin} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/dptmgr.sh ${PREFIX}/bin/dptmgr
	cd ${WRKSRC} ; ${INSTALL_DATA} \
	    dptcom.chk dptmgr.hlp dptmgr.ini dptmgr.rsc read.me \
	    ${PREFIX}/dpt
.if !exists(${X11BASE}/lib/libXm.so.1)
	${INSTALL_SCRIPT} ${WRKSRC}/libXm.so.1 ${X11BASE}/lib
.endif

.include <bsd.port.post.mk>
