# Created by: Pieter Danhieux <opr@bsdaemon.be>
# $FreeBSD$

PORTNAME=	sleuthkit
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools and library for filesystem forensic analysis

RUN_DEPENDS=	p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone

CONFLICTS=	ja-ls-[0-9]*

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/tsk3

PORTDOCS=	NEWS.txt README.txt docs/*.txt
MAN1=		blkcalc.1 blkcat.1 blkls.1 \
		blkstat.1 ffind.1 fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 img_cat.1 img_stat.1 istat.1 jcat.1 jls.1 mactime.1 \
		mmls.1 mmstat.1 mmcat.1 sigfind.1 sorter.1 \
		tsk_comparedir.1 tsk_gettimes.1 tsk_loaddb.1 tsk_recover.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
