# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbids
PORTVERSION=	20191025
CATEGORIES=	misc
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known IDs used in USB devices

LICENSE=	BSD3CLAUSE GPLv2 GPLv3
LICENSE_COMB=	dual

NO_ARCH=	yes
NO_BUILD=	yes
USES=		tar:xz

PORTDATA=	usb.ids

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${STAGEDIR}${DATADIR}/

# maintainer section:

MS_DIFF=	${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.diff
MS_DISTFILES=	usb.ids
MS_MASTER_SITE=	http://www.linux-usb.org/
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp

maketar: do-clean extract
	@${MKDIR} ${MS_WRKSRC}/
	@${FETCH_CMD} -o ${MS_WRKSRC}/${MS_DISTFILES} ${MS_MASTER_SITE}${MS_DISTFILES}
	@${AWK} '/^# Version/ { gsub(/\./, "", $$3); print $$3 }' ${MS_WRKSRC}/${MS_DISTFILES} > ${MS_VERSIONFILE}
	@${MKDIR} ${MS_WRKSRC}/${PORTNAME}-${PORTVERSION}/ ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	@${MV} ${MS_WRKSRC}/${MS_DISTFILES} ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	@${CP} ${WRKSRC}/${MS_DISTFILES} ${MS_WRKSRC}/${PORTNAME}-${PORTVERSION}/${MS_DISTFILES}
	-@cd ${MS_WRKSRC}/ && ${DIFF} -u ${PORTNAME}-${PORTVERSION}/${MS_DISTFILES} ${PORTNAME}-${MS_VERSION}/${MS_DISTFILES} > ${MS_DIFF}
	@if [ -s ${MS_DIFF} ]; then \
		${CP} -i ${MS_DIFF} ${.CURDIR}/; \
		cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${PORTNAME}-${MS_VERSION}.tar.xz ${PORTNAME}-${MS_VERSION}/; \
		sudo ${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/; \
		${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile; \
		cd ${.CURDIR}/ && ${MAKE_CMD} makesum; \
		${ECHO_MSG} "*** Update from ${PORTVERSION} to ${MS_VERSION}, diff: ${.CURDIR}/${PORTNAME}-${MS_VERSION}.diff ***"; \
	else \
		${ECHO_MSG} "*** ${MS_MASTER_SITE}${MS_DISTFILES} is unchanged (${PORTVERSION}) ***"; \
	fi

.include <bsd.port.mk>
