# $FreeBSD$

PORTNAME=	bugzilla
PORTVERSION=	4.4.4
CATEGORIES=	russian
MASTER_SITES=	SF/bugzilla-ru/bugzilla-${PORTVERSION:R}-ru/${PORTVERSION}
DISTNAME=	bugzilla-${PORTVERSION}-ru-20140422

MAINTAINER=	bz-ports@FreeBSD.org
COMMENT=	Russian localization for Bugzilla

RUN_DEPENDS=	bugzilla44>=${PORTVERSION}:devel/bugzilla44

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.ru

.include "${.CURDIR}/../../devel/bugzilla44/Makefile.common"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

# Maintainer
plist:	patch
	@( cd ${WRKSRC}/ && ${FIND} * -type f | ${AWK} '{print "%%WWWDIR%%/"$$1}' | ${SORT} > ${PLIST}.new )
	@( cd ${WRKSRC}/ && ${FIND} * -type d -empty | ${AWK} '{print "@dir %%WWWDIR%%/"$$1}' | ${SORT} -r >> ${PLIST}.new )
	@if ${DIFF} -u ${PLIST} ${PLIST}.new ; then \
		${ECHO_MSG} no pkg-plist changes; \
		${RM} ${PLIST}.new ; \
	fi

.include <bsd.port.mk>
