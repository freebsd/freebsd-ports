# New ports collection makefile for:	slnr
# Version required:	2.13
# Date created:		21 July 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.1.1.1 1996/11/01 08:08:54 asami Exp $
#

DISTNAME=	slnr
PKGNAME=	slnr-2.13
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/readers/off-line/slnr/ \
		ftp://ftp.adelaide.edu.au/pub/news/readers/off-line/slnr/
DISTFILES=	part1.Z part2.Z part3.Z

MAINTAINER=	ac199@freenet.hamilton.on.ca

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

DIST_SUBDIR=	slnr
NO_WRKSUBDIR=	yes
ALL_TARGET=	slnr
EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	| sed -ne '/^\#!\/bin\/sh/,$$p' | sh
MAN1=		slnr.1

EXTRAFILES=	default.dot.slnrrc \
 		porting.notes slnr.1 LICENSE

DOCFILES=	porting.notes soup12.doc slnr.doc LICENSE
DOCFILES+=	default.dot.slnrrc

post-extract:
.for l in ${EXTRAFILES}
		@cp ${FILESDIR}/${l} ${WRKSRC}
.endfor

do-install:
.if !defined{NOPORTDOCS}
	mkdir -p ${PREFIX}/share/doc/slnr
	cd ${WRKSRC}; \
		${INSTALL_DATA} ${DOCFILES} ${PREFIX}/share/doc/slnr
.endif
	${INSTALL_MAN} ${WRKSRC}/slnr.1 ${PREFIX}/man/man1/slnr.1
	${INSTALL_PROGRAM} ${WRKSRC}/slnr ${PREFIX}/bin

.include <bsd.port.mk>
