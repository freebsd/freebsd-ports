# New ports collection makefile for:    golded+
# Date created:                         20 October 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	golded+
PORTVERSION=	1.1.5.a${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=golded-plus
DISTNAME=	gps-${SNAPDATE}
SNAPDATE=	20031224

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	GoldEd+ (FTN message editor)

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		golded.1 goldnode.1 rddt.1
DOCS=		copying copying.lib license.txt notework.txt rusfaq.txt tips.txt

post-patch:
	@cp ${WRKSRC}/golded3/mygolded.__h ${WRKSRC}/golded3/mygolded.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gedlnx ${PREFIX}/bin/golded
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gnlnx ${PREFIX}/bin/goldnode
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/rddtlnx ${PREFIX}/bin/rddt
	@for i in ${MAN1}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/$$i ${PREFIX}/man/man1; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@for i in charset colorset config template; do \
		${MKDIR} ${EXAMPLESDIR}/$$i; \
		${FIND} ${WRKSRC}/cfgs/$$i -maxdepth 1 -type f | ${XARGS} -n 1 -J @ ${INSTALL_DATA} @ ${EXAMPLESDIR}/$$i; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/manuals/gold_ref.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/manuals/gold_usr.txt ${DOCSDIR}
	@for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$i ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
