# New ports collection makefile for:	tei-lite
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Lite/DTD/
PKGNAMESUFFIX=	-lite
DISTFILES=	teilite.dtd teilite.tag
EXTRACT_ONLY=	# Empty

MAINTAINER=	henrik.motakef@web.de

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_BUILD=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG} CATALOG=${CATALOG}
INSTDIR=	${PREFIX}/share/sgml/tei/lite
CATALOG=	${PREFIX}/share/sgml/catalog
MKCATALOG=	${PREFIX}/sbin/mkcatalog

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teilite.dtd ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teilite.tag ${INSTDIR}
	@${SED} -e 's!%%INSTDIR%%!${INSTDIR}!' ${FILESDIR}/catalog \
	  > ${INSTDIR}/catalog

post-install:
	@${MKCATALOG} -q -c ${CATALOG} install ${PORTNAME}/lite

.include <bsd.port.mk>
