# New ports collection makefile for:	tei-xlite
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Lite/DTD/
PKGNAMESUFFIX=	-xlite
DISTNAME=	teixlite
EXTRACT_SUFX=	.dtd
EXTRACT_ONLY=	# Empty

MAINTAINER=	henrik.motakef@web.de

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_BUILD=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG} CATALOG=${CATALOG}
INSTDIR=	${PREFIX}/share/xml/tei/xlite
CATALOG=	${PREFIX}/share/xml/catalog
MKCATALOG=	${PREFIX}/sbin/mkcatalog

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teixlite.dtd ${INSTDIR}
	@${SED} -e 's!%%INSTDIR%%!${INSTDIR}!' ${FILESDIR}/catalog \
	  > ${INSTDIR}/catalog

post-install:
	@${MKCATALOG} -q -c ${CATALOG} install ${PORTNAME}/xlite

.include <bsd.port.mk>
