# Created by: Adi Pircalabu <apircalabu@bitdefender.com>
# $FreeBSD$

PORTNAME=	bdc
PORTVERSION=	7.0.1
PORTREVISION=	2
CATEGORIES=	security
#MASTER_SITES=	# http://download.bitdefender.com/freebsd/${BDREL}/final/
DISTNAME=	${PORTNAME}-${PORTVERSION}.2-fbsd${BDREL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitDefender Console Antivirus for FreeBSD

LIB_DEPENDS=	libc.so.5:misc/compat5x

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

ONLY_FOR_ARCHS=	i386
RESTRICTED=	License prohibits redistribution

BDREL=		5

SUB_LIST=	bdc pkg-message

OPTIONS_DEFINE=	DOCS

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
	cd ${WRKSRC} && ${COPYTREE_SHARE} bdc ${STAGEDIR}${PREFIX}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}/bdc
	${CHMOD} -R a=rX,u+w ${STAGEDIR}${PREFIX}/bdc/

	${MV} ${STAGEDIR}${PREFIX}/bdc/doc ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${STAGEDIR}${PREFIX}/bdc/man/bdc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${RM} -f ${STAGEDIR}${PREFIX}/bdc/man

	${INSTALL_SCRIPT} ${WRKDIR}/bdc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
