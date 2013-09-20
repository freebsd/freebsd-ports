# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.0.10
CATEGORIES=	russian
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-ru/bugzilla-${PORTVERSION:R}-ru/${PORTVERSION}
DISTNAME=	bugzilla-${PORTVERSION}-ru-20130222

MAINTAINER=	bugzilla@FreeBSD.org
COMMENT=	Russian localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.ru

NO_STAGE=	yes
.include "${.CURDIR}/../../devel/bugzilla/Makefile.common"

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${PAX} -r -w * ${WWWDIR})
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

# Maintainer
plist:	patch
	@( cd ${WRKSRC}/ && ${FIND} * -type f | ${AWK} '{print "%%WWWDIR%%/"$$1}' | ${SORT} > ${PLIST}.new )
	@( cd ${WRKSRC}/ && ${FIND} * -type d | ${AWK} '{print "@dirrmtry %%WWWDIR%%/"$$1}' | ${SORT} -r >> ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
