# Created by: Thomas E. Zander <riggs@rrr.de>
# $FreeBSD$

PORTNAME=	freesbie
PORTVERSION=	2.0.20070710
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/riggs/freesbie
DISTNAME=	${PORTNAME}-${PORTVERSION:S/2.0.//}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Yet another cool answer to the system-on-cd question

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	cdrecord:sysutils/cdrtools

USES=		tar:bzip2
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}2

ONLY_FOR_ARCHS=	amd64 i386 powerpc
ONLY_FOR_ARCHS_REASON=	FreeSBIE build system only supports amd64, i386 and powerpc

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-pkgng

pre-configure:
	@${SED} -e "s:%%ARCH%%:${ARCH}:g" ${FILESDIR}/conf-arch-FREESBIE.in > ${WRKSRC}/conf/${ARCH}/FREESBIE

do-install:
	@ ${MKDIR} ${STAGEDIR}${DATADIR}
	@ ${RM} -f ${WRKSRC}/scripts/iso.sh.orig \
		${WRKSRC}/scripts/pkginstall.sh.orig \
		${WRKSRC}/scripts/pkgselect.sh.orig
	@ cd ${WRKSRC} && ${FIND} . -type f -print | tar -cf - -T - | \
	tar -xf - -C ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
