# New ports collection makefile for:	The Sleuth Kit
# Date created:				2003-08-12
# Whom:					Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	3.1.2
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The @stake Sleuth Kit for forensic analysis

CONFLICTS=	ja-ls-[0-9]*

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/tsk3

PORTDOCS=	NEWS.txt README.txt docs/*.txt
MAN1=		blkcalc.1 blkcat.1 blkls.1 \
		blkstat.1 ffind.1 fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 img_cat.1 img_stat.1 istat.1 jcat.1 jls.1 mactime.1 \
		mmls.1 mmstat.1 mmcat.1 sigfind.1 sorter.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
