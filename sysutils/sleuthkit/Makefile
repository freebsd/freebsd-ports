# New ports collection makefile for:	The Sleuth Kit
# Date created:				2003-08-12
# Whom:					Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	sleuthkit
PORTVERSION=	2.51
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The @stake Sleuth Kit for forensic analysis

RUN_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip

CONFLICTS=	ja-ls-[0-9]*

GNU_CONFIGURE=	yes
USE_PERL5=	yes
DATADIR=	${PREFIX}/share/tsk

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500033
BROKEN=		Does not build on pre-GEOM versions of FreeBSD
.endif

DOCS=		CHANGES.txt README.txt docs/*.txt
MAN1=		disk_sreset.1 disk_stat.1 dls.1 dstat.1 fls.1 fsstat.1 \
		hfind.1 icat.1 ifind.1 img_cat.1 img_stat.1 istat.1 jcat.1 \
		mactime.1 mmls.1 sigfind.1 mmstat.1 sorter.1 dcalc.1 dcat.1 \
		ffind.1 ils.1 jls.1

post-extract:
# Do not install own Date::Manip, use system-wide one
	@${REINPLACE_CMD} -e 's,[[:graph:]]*Date[[:graph:]]*,,g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/use lib/d' ${WRKSRC}/tools/timeline/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
