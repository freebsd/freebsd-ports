# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $FreeBSD$
#

PORTNAME=	citrix_ica
PORTVERSION=	9.00
CATEGORIES=	net comms linux
MASTER_SITES=
DISTNAME=	${PORTNAME}-linuxx86-${PORTVERSION}

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Citrix(R) client for the Microsoft Windows Terminal Server

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXaw.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/X11R6/lib/libXm.so.3:${PORTSDIR}/x11-toolkits/linux-openmotif

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CDIR=		${PREFIX}/ICAClient
BINDIR=		${PREFIX}/bin

NSCP=	/usr/local/libexec/netscape \
	/usr/local/libexec/netscape-linux \
	/usr/local/netscape \
	/usr/local/netscape-linux \
	/usr/local/lib/netscape \
	/usr/local/lib/netscape-linux \
	${MOZILLA_HOME}

PLIST_SUB=	MOZILLA_HOME=${MOZILLA_HOME}

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/bin/kde-config)
HAVE_KDE=	"\\ny"
.endif

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.'
.endif

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	@${ECHO} ""
	@${ECHO} "You have to fetch the file manually after reading and"
	@${ECHO} "agreeing to the license at:"
	@${ECHO} ""
	@${ECHO} "http://www.citrix.com/download/bin/license.asp?client=linux"
	@${ECHO} ""
	@${ECHO} "Once linuxx86.tar.gz has been downloaded move it to"
	@${ECHO} "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} and restart the build."
	@${ECHO} ""
	@${FALSE}
.endif

do-install:
	@if (test -d "${CDIR}") ; \
	then \
		${ECHO} "-----------------------------------------------------------" ; \
		${ECHO} "" ; \
		${ECHO} "A ${CDIR} installation does already exist." ; \
		${ECHO} "Please move it away or delete the old port" ; \
		${ECHO} "" ; \
		${ECHO} "-----------------------------------------------------------" ; \
		${FALSE} ; \
	fi
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && /bin/sh -c './setupwfc'
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica

.include <bsd.port.post.mk>
