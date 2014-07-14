# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	asr-utils
PORTVERSION=	3.04
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/u160raid/unix/ \
		ftp://ftp.adaptec.com/raid/u160raid/unix/
DISTNAME=	u160raid_sm_v304_fbsd411
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptec ASR RAID Management Software

LIB_DEPENDS+=	libc.so.4:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes
BINS=		raidutil dpteng dptcom dptsig
.ifndef (WITHOUT_X11)
USE_XORG=	x11
BINS+=		dptscom dptmgr
.endif
MAN8=		raidutil.8

.if !defined(WITHOUT_X11) && !exists(${LOCALBASE}/lib/libXm.so.1)
# we shall install our own libXm.so.1, enable it in pkg-plist
PLIST_SUB+=	LIBXM=""
.else
PLIST_SUB+=	LIBXM="@comment "
.endif

.ifndef (WITHOUT_X11)
PLIST_SUB+=	X11=""
NO_STAGE=	yes
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
.if !exists(${LOCALBASE}/lib/libXm.so.1)
	${INSTALL_SCRIPT} ${WRKSRC}/libXm.so.1 ${LOCALBASE}/lib
.endif
.else
NO_BUILD=	yes
PLIST_SUB+=	X11="@comment "
do-install:
	${MKDIR} ${PREFIX}/dpt
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} ${BINS} ${PREFIX}/dpt ; \
		${INSTALL_DATA} read.me dptcom.chk ${PREFIX}/dpt
.for bin in ${BINS}
	${LN} -sf ${PREFIX}/dpt/${bin} ${PREFIX}/bin
.endfor
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/raidutil.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
