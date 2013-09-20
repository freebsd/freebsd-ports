# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	5.2.12
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-docs-${PORTVERSION}.tar.bz2

MAINTAINER=	dan@langille.org
COMMENT=	Bacula document set

NO_BUILD=	yes

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	*.pdf

.ifdef NOPORTDOCS
IGNORE=		consists of only documentation, please undef NOPORTDOCS and try again
.endif

NO_STAGE=	yes
do-install:
	${MKDIR} ${DOCSDIR}

	${FIND} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${DOCSDIR}/ \;

.include <bsd.port.mk>
