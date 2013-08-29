# Created by: Adi Pircalabu <apircalabu@bitdefender.com>
# $FreeBSD$

PORTNAME=	bdc
PORTVERSION=	7.0.1
PORTREVISION=	2
CATEGORIES=	security
#MASTER_SITES=	# http://download.bitdefender.com/freebsd/${BDREL}/final/
DISTNAME=	${PORTNAME}-${PORTVERSION}.2-fbsd${BDREL}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	BitDefender Console Antivirus for FreeBSD

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

ONLY_FOR_ARCHS=	i386
RESTRICTED=	License prohibits redistribution

BDREL=		5

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	you have to fetch ${DISTNAME}${EXTRACT_SUFX} manually after reading\
and agreeing to the license at:\
http://download.bitdefender.com/SMB/Workstation_Security_and_Management/BitDefender_Antivirus_Scanner_for_Unices/Unix/Old/EN/freebsd/Ver_${BDREL}/.\
Here is a direct link to the distribution file:\
http://download.bitdefender.com/SMB/Workstation_Security_and_Management/BitDefender_Antivirus_Scanner_for_Unices/Unix/Old/EN/freebsd/Ver_${BDREL}/bdc-7.0.1.2-fbsd${BDREL}.tar.gz.\
Once the file has been downloaded, move it to ${DISTDIR} and restart the build
.endif

do-install:
	@cd ${WRKDIR} && ${TAR} -cf - bdc | ${TAR} -xf - -C ${PREFIX}/
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/bdc
	@${CHMOD} -R a=rX,u+w ${PREFIX}/bdc/

	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%PORTNAME%%|${PORTNAME}|g' \
		< ${PKGDIR}/pkg-message > ${PKGMESSAGE}

	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g'  \
		< ${FILESDIR}/bdc > ${PREFIX}/bin/bdc
	@${CHMOD} +x ${PREFIX}/bin/bdc

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
