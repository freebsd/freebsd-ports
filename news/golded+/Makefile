# New ports collection makefile for:    golded+
# Date created:                         20 October 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	golded+
PORTVERSION=	1.1.4.7
CATEGORIES=	news mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=golded-plus
DISTNAME=	gps114-7

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	GoldEd+ (FTN message editor)

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		golded.1 goldnode.1 rddt.1

post-patch:
	@cp ${WRKSRC}/golded3/mygolded.__h ${WRKSRC}/golded3/mygolded.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gedlnx ${PREFIX}/bin/golded
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/gnlnx ${PREFIX}/bin/goldnode
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/rddtlnx ${PREFIX}/bin/rddt
	@for i in ${MAN1}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/$$i ${PREFIX}/man/man1; \
	done
	@${MKDIR} ${PREFIX}/share/examples/golded+
	@(cd ${WRKSRC}/cfgs && ${TAR} cf - --exclude CVS * | \
	  ${TAR} xf - -C ${PREFIX}/share/examples/golded+)
	@${MKDIR} ${PREFIX}/share/doc/golded+
	@${INSTALL_DATA} ${WRKSRC}/manuals/gold_ref.txt ${PREFIX}/share/doc/golded+
	@${INSTALL_DATA} ${WRKSRC}/manuals/gold_usr.txt ${PREFIX}/share/doc/golded+

.include <bsd.port.mk>
