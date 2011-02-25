# New ports collection makefile for:	pciids
# Date created:		2006-08-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/misc/pciids/Makefile,v 1.11 2008/03/23 06:57:57 marcus Exp $
#

PORTNAME=	pciids
PORTVERSION=	20110206
CATEGORIES=	misc
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	gnome@FreeBSD.org
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

.include <bsd.port.pre.mk>

# Below only contains code to create a tar file for this beast
CT_DATE!=	date "+%Y%m%d"
CT_WRKSRC=	${WRKDIR}/tmp
CT_DESTDIR=	${PORTNAME}-${CT_DATE}
CT_TEMPDIR=	${CT_WRKSRC}/${CT_DESTDIR}
CT_MASTER_SITE=	http://pciids.sourceforge.net/v2.2
CT_DISTFILES=	pci.ids

maketar: extract
	${MKDIR} ${CT_TEMPDIR}
.for file in ${CT_DISTFILES}
	(cd ${CT_TEMPDIR} && ${FETCH_CMD} ${CT_MASTER_SITE}/${file})
.endfor
	${DIFF} -u ${WRKSRC}/pci.ids ${CT_TEMPDIR}/pci.ids || ${TRUE}
	(cd ${CT_WRKSRC} && ${TAR} -jcf ${PORTNAME}-${CT_DATE}.tar.bz2 ${CT_DESTDIR})
	${SED} -i.bak -e 's|${PORTVERSION}|${CT_DATE}|' ${.CURDIR}/Makefile
	@(cd ${.CURDIR} && ${CP} -f ${CT_WRKSRC}/${PORTNAME}-${CT_DATE}.tar.bz2 ${DISTDIR} && \
		${MAKE} makesum)

.include <bsd.port.post.mk>
