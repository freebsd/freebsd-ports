# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.20.5
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	fop
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print formatter driven by XSL formatting

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.2+

SUB_FILES=	fop.sh

do-install:
	${MKDIR} ${DATADIR}/build
	cd ${WRKSRC}; \
	  ${INSTALL_DATA} CHANGES LICENSE README ReleaseNotes.html STATUS ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/fop.sh ${PREFIX}/bin/fop
	cd ${WRKSRC} \
	  && ${FIND} conf lib -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} conf lib -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	cd ${WRKSRC}/src \
	  && ${FIND} hyph -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} hyph -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${DATADIR}/build/
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/build/site \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
