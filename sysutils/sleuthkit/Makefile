# New ports collection makefile for:	The Sleuth Kit
# Date created:				2003-08-12
# Whom:					Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	2.00
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	The @stake Sleuth Kit for forensic analysis

USE_PERL5=	yes
USE_REINPLACE=	yes

PROGS=		dcalc dcat disk_sreset disk_stat dls dstat ffind \
		fls fsstat hfind icat ifind ils img_stat istat \
		jcat jls md5 mmls mmstat sha1 sigfind srch_strings
SCRIPTS=	mactime sorter
DOCS=		CHANGES.txt README.txt docs/*
MAN1=		dcalc.1 dcat.1 disk_sreset.1 disk_stat.1 dls.1 \
		dstat.1 ffind.1 fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 img_stat.1 istat.1 jcat.1 jls.1 mactime.1 mmls.1 \
		sigfind.1 sorter.1

post-patch:
	@${REINPLACE_CMD} -e 's/BSD5)$$/& || defined(FREEBSD6)/' \
		${WRKSRC}/src/misc/tsk_os.h
	@${REINPLACE_CMD} -E -e 's/^CC[[:space:]]*=/CC \?=/' \
		-e 's/[[:space:]]+file test[[:space:]]*$$//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CC[[:space:]]*=/d' -e 's/\$$(OPT) \$$(DEBUG)//' \
		-e 's/^CFLAGS[[:space:]]*=/CFLAGS \+=/' \
		${WRKSRC}/src/disktools/Makefile ${WRKSRC}/src/fstools/Makefile \
		${WRKSRC}/src/hashtools/Makefile ${WRKSRC}/src/imgtools/Makefile \
		${WRKSRC}/src/misc/Makefile ${WRKSRC}/src/mmtools/Makefile \
		${WRKSRC}/src/srchtools/Makefile

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
