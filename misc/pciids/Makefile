# New ports collection makefile for:	pciids
# Date created:		2006-08-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/misc/pciids/Makefile,v 1.11 2008/03/23 06:57:57 marcus Exp $
#

PORTNAME=	pciids
PORTVERSION=	20111002
CATEGORIES=	misc
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known ID's used in PCI devices

LICENSE=	BSD GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/pci.ids
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DATADIR}

# maintainer section:

MS_DIFF=	${MS_WRKSRC}/${MS_DISTFILES}.diff
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp
MS_MASTER_SITE=	http://pciids.sourceforge.net/v2.2/
MS_DISTFILES=	pci.ids

maketar: do-clean extract
	${MKDIR} ${MS_WRKSRC}/
	${FETCH_CMD} -o ${MS_WRKSRC}/${MS_DISTFILES} ${MS_MASTER_SITE}${MS_DISTFILES}
	${GREP} '^#	Version: [0-9.]\{10\}$$' ${MS_WRKSRC}/${MS_DISTFILES} \
		| ${SED} -e 's|^.* \([0-9]*\)\.\([0-9]*\)\.\([0-9]*\)$$|\1\2\3|' \
			> ${MS_VERSIONFILE}
	${MKDIR} ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	${MV} ${MS_WRKSRC}/${MS_DISTFILES} ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	(${DIFF} -u ${WRKSRC}/${MS_DISTFILES} ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/${MS_DISTFILES} > ${MS_DIFF}) || ${TRUE}
	if [ -s ${MS_DIFF} ]; then \
		cd ${MS_WRKSRC}/ && ${TAR} -jcf ${PORTNAME}-${MS_VERSION}.tar.bz2 ${PORTNAME}-${MS_VERSION}/; \
		${SED} -i '' -e "s|${PORTVERSION}|${MS_VERSION}|" ${.CURDIR}/Makefile; \
		${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.bz2 ${DISTDIR}/; \
		cd ${.CURDIR}/ && ${MAKE} makesum; \
		${ECHO_MSG} "*** Update from ${PORTVERSION} to ${MS_VERSION}, diff: ${MS_DIFF} ***"; \
	else \
		${ECHO_MSG} "*** ${MS_MASTER_SITE}${MS_DISTFILES} is unchanged (${PORTVERSION}) ***"; \
	fi

.include <bsd.port.mk>
