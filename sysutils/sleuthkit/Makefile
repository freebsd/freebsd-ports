# New ports collection makefile for:	The Sleuth Kit
# Date created:				2003-08-12
# Whom:					Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	1.73
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	The @stake Sleuth Kit for forensic analysis

USE_PERL5=	yes
USE_REINPLACE=	yes

PROGS=		dcalc dcat diskstat dls dstat ffind fls fsstat \
		hfind icat ifind ils istat jcat jls md5 mmls sha1 \
		sigfind sstrings
SCRIPTS=	mactime sorter
DOCS=		README.txt docs/* tct.docs/*
MAN1=		dcalc.1 dcat.1 diskstat.1 dls.1 dstat.1 ffind.1 \
		fls.1 fsstat.1 hfind.1 icat.1 ifind.1 ils.1 istat.1 \
		jcat.1 jls.1 mactime.1 mmls.1 sigfind.1 sorter.1

post-patch:
	@${REINPLACE_CMD} -e 's/BSD5)$$/BSD5) || defined(FREEBSD6)/' \
		${WRKSRC}/src/fstools/fs_os.h ${WRKSRC}/src/mmtools/mm_tools.h \
		${WRKSRC}/src/srchtools/srch_os.h
	@${REINPLACE_CMD} -E -e 's/^CC[[:space:]]*=/CC \?=/' \
		-e 's/[[:space:]]+file test[[:space:]]*$$//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CC[[:space:]]*=/d' -e 's/\$$(OPT) \$$(DEBUG)//' \
		-e 's/^CFLAGS[[:space:]]*=/CFLAGS \+=/' \
		${WRKSRC}/src/disktools/Makefile ${WRKSRC}/src/fstools/Makefile \
		${WRKSRC}/src/hashtools/Makefile ${WRKSRC}/src/misc/Makefile \
		${WRKSRC}/src/mmtools/Makefile ${WRKSRC}/src/srchtools/Makefile

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
