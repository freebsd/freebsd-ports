# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.93
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:fop/} \
	${MASTER_SITE_SOURCEFORGE:S/$/:hyph/}
MASTER_SITE_SUBDIR=	xmlgraphics/fop/:fop offo/:hyph
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
#DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DISTFILES=	${DISTNAME}.tar.gz:fop offo-hyphenation.zip:hyph
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print formatter driven by XSL formatting

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ANT=	yes

post-extract:
	cd ${WRKDIR} && unzip ${DISTDIR}/offo-hyphenation.zip
	cp ${WRKDIR}/offo-hyphenation/hyph/*.xml ${WRKSRC}/hyph

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}; \
	  ${INSTALL_DATA} LICENSE README known-issues.xml status.xml build.xml ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/fop ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fop ${DATADIR}/fop
	${LN} -s ${DATADIR}/fop ${PREFIX}/bin/fop
	cd ${WRKSRC} \
	  && ${FIND} conf lib hyph build -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} conf lib hyph build -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.include <bsd.port.mk>
