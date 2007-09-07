# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $FreeBSD$
#

PORTNAME=	citrix_ica
PORTVERSION=	10.6
PORTREVISION=	1
CATEGORIES=	net comms linux
MASTER_SITES=
DISTNAME=	${PORTNAME}-linuxx86-${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Citrix(R) Presentation Server(TM) client

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXm.so.3:${PORTSDIR}/x11-toolkits/linux-openmotif

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
RESTRICTED=	License prohibits redistribution
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CDIR=		${PREFIX}/ICAClient
BINDIR=		${PREFIX}/bin
CERTDIR=	${CDIR}/keystore/cacerts

PLIST_SUB=	MOZILLA_HOME=${MOZILLA_HOME}
.if defined(ICA_CERTS)
PLIST_SUB+=	HAVE_ICA_CERTS="" ICA_CERTS="${ICA_CERTS}" CERTDIR="${CERTDIR}"
.else
PLIST_SUB+=	HAVE_ICA_CERTS="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.'
.endif

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	@${ECHO} ""
	@${ECHO} "You have to fetch the file manually from"
	@${ECHO} ""
	@${ECHO} "http://www.citrix.com/English/SS/downloads/details.asp?dID=2755&downloadID=3323&pID=186"
	@${ECHO} ""
	@${ECHO} "Once en.linuxx86.tar.gz has been downloaded move it to"
	@${ECHO} "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} and restart the build."
	@${ECHO} ""
	@${FALSE}
.endif

.if defined(ICA_CERTS)
pre-fetch:
.for f in ${ICA_CERTS}
	@echo "Checking ${f}"
.if !exists(${DISTDIR}/${f})
	@echo "Cert ${f} not found."
	@exit 1
.endif
.endfor
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
	cd ${WRKSRC} && ${SH} -c './setupwfc'
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

.if defined(ICA_CERTS)
.for f in ${ICA_CERTS}
	${INSTALL_DATA} ${DISTDIR}/${f} ${CERTDIR}
.endfor
.endif

.include <bsd.port.post.mk>
