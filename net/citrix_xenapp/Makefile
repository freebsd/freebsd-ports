# New ports collection makefile for:	Citrix(R) ICA(R) Client
# Date created:         20 Sep 1998
# Whom:                 msmith
#
# $FreeBSD$
#

PORTNAME=	citrix_ica
PORTVERSION=	6.20.973
CATEGORIES=	net comms linux
MASTER_SITES=
DISTNAME=	linuxx86

MAINTAINER=	mbr@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"License prohibits redistribution"
IS_INTERACTIVE=	"Noisy license agreement ignores stdin"

DIST_SUBDIR=	citrix_ica
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

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the file manually after reading and agreeing to the license at: http://www.citrix.com/download/bin/license.asp?client=linux   Once ${DISTFILES} has been downloaded, move it to ${DISTDIR}/${DIST_SUBDIR} and then restart this build.'
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

	@${ECHO} -e "1\n${CDIR}\ny\ny\ny\ny\n3" > ${WRKSRC}/response ;
	@for dir in ${NSCP}; do \
		if [ -e $${dir}/plugins/libnullplugin.so ]; then \
			BIN=`${FILE} $${dir}/plugins/libnullplugin.so | ${AWK} '{print $$11}'` ; \
			case $${BIN} in \
			\(SYSV\),) \
				${ECHO} -e "1\n${CDIR}\ny\ny\ny\n3" > ${WRKSRC}/response ; \
			esac \
		fi \
	done

	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% < ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x
	cd ${WRKSRC} && ${LINUXBASE}/bin/sh -c './setupwfc < response'
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica

.include <bsd.port.post.mk>
