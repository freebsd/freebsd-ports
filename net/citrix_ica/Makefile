# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Version required:     2.80.76
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $Id: Makefile,v 1.4 1998/12/30 03:56:28 obrien Exp $
#

DISTNAME=       linux
PKGNAME=	citrix_ica-2.8.1
CATEGORIES=	comms
MASTER_SITES=   "Distfile must be fetched manually"
EXTRACT_SUFX=	.tar.z

MAINTAINER=     msmith@FreeBSD.ORG

RUN_DEPENDS=    /compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_lib

DIST_SUBDIR=	citrix_ica
NO_WRKSUBDIR=	Yes
NO_BUILD=       Yes
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

CDIR=           ${PREFIX}/lib/ICAClient
BINDIR=		${PREFIX}/bin

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The source to this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the source manually after reading and agreeing to the license at: http://download.citrix.com/download.asp?client=LINUX   Once ${DISTFILES} has been downloaded, move it to ${DISTDIR} and then restart this build.'
.endif

do-install:
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/response \
		> ${WRKSRC}/response
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && ./setupwfc < response
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica

.include <bsd.port.post.mk>
