# New ports collection makefile for:	pciids
# Date created:		2006-08-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pciids
PORTVERSION=	20120711
CATEGORIES=	misc
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known IDs used in PCI devices

LICENSE=	BSD GPLv2 GPLv3
LICENSE_COMB=	dual

USE_XZ=		yes
NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/pci.ids
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DATADIR}/

# maintainer section:

MS_DIFF=	${MS_WRKSRC}/${MS_DISTFILES}.diff
MS_DISTFILES=	pci.ids
MS_MASTER_SITE=	http://pci-ids.ucw.cz/
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp

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
		cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${PORTNAME}-${MS_VERSION}.tar.xz ${PORTNAME}-${MS_VERSION}/; \
		${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/; \
		${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile; \
		cd ${.CURDIR}/ && ${MAKE} makesum; \
		${CP} -i ${MS_DIFF} ${.CURDIR}/${PORTNAME}-${MS_VERSION}.diff; \
		${ECHO_MSG} "*** Update from ${PORTVERSION} to ${MS_VERSION}, diff: ${.CURDIR}/${PORTNAME}-${MS_VERSION}.diff ***"; \
	else \
		${ECHO_MSG} "*** ${MS_MASTER_SITE}${MS_DISTFILES} is unchanged (${PORTVERSION}) ***"; \
	fi

.include <bsd.port.mk>
