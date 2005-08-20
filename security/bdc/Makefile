# New ports collection makefile for:   bdc
# Date created:                        4 December 2004
# Whom:                                Adi Pircalabu <apircalabu@bitdefender.com>
#
# $FreeBSD$
#

PORTNAME=	bdc
PORTVERSION=	7.0.1
CATEGORIES=	security
MASTER_SITES=	# http://download.bitdefender.com/freebsd/${BDREL}/beta/
DISTNAME=	${PORTNAME}-${PORTVERSION}-fbsd${BDREL}

MAINTAINER=	apircalabu@bitdefender.com
COMMENT=	BitDefender Console Antivirus for FreeBSD

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 490000 || ${OSVERSION} >= 500000 && ${OSVERSION} < 502001
IGNORE=		"requires FreeBSD-STABLE \(4.9 or later\), or FreeBSD-CURRENT \(5.2.1 or later\)"
.elif ${OSVERSION} < 500000
BDREL=		4
.else
BDREL=		5
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

ONLY_FOR_ARCHS=	i386
RESTRICTED=     "License prohibits redistribution"

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=	/usr/bin/printf
IGNORE=	:\n\
You have to fetch ${DISTNAME}${EXTRACT_SUFX} manually after\n\
reading and agreeing to the license at:\n\
http://download.bitdefender.com/freebsd/${BDREL}/beta/LICENSE\n\
A direct link to the distribution file:\n\
http://download.bitdefender.com/freebsd/${BDREL}/beta/${DISTNAME}${EXTRACT_SUFX}\n\
Once the file has been downloaded move it to\n\
${DISTDIR} and restart the build.\n
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
