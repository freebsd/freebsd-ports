# New ports collection makefile for:	The Sleuth Kit
# Date created:				2003-08-12
# Whom:					Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	2.09
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The @stake Sleuth Kit for forensic analysis

RUN_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip

CONFLICTS=	ja-ls-[0-9]*

USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500033
BROKEN=		Does not build on pre-GEOM versions of FreeBSD
.endif

PROGS=		dcalc dcat disk_sreset disk_stat dls dstat ffind \
		fls fsstat hfind icat ifind ils img_cat img_stat istat \
		jcat jls md5 mmls mmstat sha1 sigfind srch_strings
SCRIPTS=	mactime sorter
DOCS=		CHANGES.txt README.txt docs/*.txt docs/api-doc/*
MAN1=		dcalc.1 dcat.1 disk_sreset.1 disk_stat.1 dls.1 \
		dstat.1 ffind.1 fls.1 fsstat.1 hfind.1 icat.1 ifind.1 \
		ils.1 img_cat.1 img_stat.1 istat.1 jcat.1 jls.1 mactime.1 \
		mmls.1 sigfind.1 sorter.1

post-patch:
	@${REINPLACE_CMD} -E -e 's/^CC[[:space:]]*=/CC \?=/' \
		-e 's/[[:space:]]+file test[[:space:]]*$$//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CC[[:space:]]*=/d' \
		-e 's/\$$(OPT) \$$(DEBUG)//' \
		-e 's/^CFLAGS[[:space:]]*=/CFLAGS \+=/' \
		${WRKSRC}/src/disktools/Makefile \
		${WRKSRC}/src/fstools/Makefile \
		${WRKSRC}/src/hashtools/Makefile \
		${WRKSRC}/src/imgtools/Makefile \
		${WRKSRC}/src/auxtools/Makefile \
		${WRKSRC}/src/mmtools/Makefile \
		${WRKSRC}/src/srchtools/Makefile
	@${REINPLACE_CMD} -e 's/$${BIN_DIR}file/\/usr\/bin\/file/' \
		${WRKSRC}/src/sorter/sorter.base

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/api-doc
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS:M*.txt} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS:N*.txt} ${DOCSDIR}/api-doc
.endif
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${PROGS} ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>
