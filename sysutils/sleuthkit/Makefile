# New ports collection makefile for:    sleuthkit
# Date created:         2003-08-12
# Whom:                 Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	1.64
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	The @stake Sleuth Kit for forensic analysis

USE_PERL5=	yes
DOCS=		README docs/* tct.docs/*
MAN1=		dcalc.1 dcat.1 dls.1 dstat.1 ffind.1 \
		fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 istat.1 mactime.1 mmls.1 sorter.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=		"Does not build on FreeBSD >= 6.x"
.endif

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sleuthkit
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/sleuthkit
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mactime ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sorter ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} dcalc dcat dls dstat ffind \
		fls fsstat hfind icat ifind ils \
		istat sha1 mmls file md5 ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>
