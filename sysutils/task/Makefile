# New ports collection makefile for:    task
# Date created:         Sun Oct  6 23:52:10 PDT 2002
# Whom:                 Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	task
PORTVERSION=	1.50
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=sleuthkit

MAINTAINER=	jan@atstake.com

USE_PERL5=	yes
DOCS=		README docs/* tct.docs/*
MAN1=		blockcalc.1 dcalc.1 dcat.1 dls.1 dstat.1 ffind.1 \
		find_file.1 find_inode.1 fls.1 fsstat.1 icat.1 ifind.1 \
		ils.1 istat.1 mactime.1 unrm.1

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/task
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/task
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mactime ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} dcalc dcat dls dstat ffind \
		icat fls fsstat icat ifind ils istat ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
