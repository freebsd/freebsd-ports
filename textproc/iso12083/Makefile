# Created by: jfieber
# $FreeBSD$

PORTNAME=	iso12083
PORTVERSION=	1993
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kuriyama/iso12083
DISTFILES=	article.dtd book.dtd maths.dtd serial.dtd
EXTRACT_ONLY=	# empty

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	SGML DTDs from the The Electronic Publishing Special Interest Group

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

DIST_SUBDIR=	iso12083

NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

INSTDIR=	${STAGEDIR}${PREFIX}/share/sgml/iso12083

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@for i in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${INSTDIR}/$$i; \
	done
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog

.include <bsd.port.mk>
