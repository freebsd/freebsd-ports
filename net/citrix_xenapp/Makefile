# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Version required:     2.80.76
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $Id: Makefile,v 1.2 1998/11/06 07:09:15 msmith Exp $
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

do-fetch:
        @if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
           ${ECHO} "" ; \
           ${ECHO} "  The source to this port may not be automatically fetched" 
; \
           ${ECHO} "  due to licensing restrictions. You MUST fetch the source" 
; \
           ${ECHO} "  manually after reading and agreeing to the license at:" ; 
\
           ${ECHO} "" ; \
           ${ECHO} "      http://download.citrix.com/download.asp?client=LINUX" ; \
           ${ECHO} "" ; \
           ${ECHO} "  Once ${DISTFILES} has been downloaded, move it to ${DISTDI
R}" ; \
           ${ECHO} "  and then restart this build." ; \
           ${ECHO} "" ; \
           exit 1 ; \
        fi

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

.include <bsd.port.mk>
