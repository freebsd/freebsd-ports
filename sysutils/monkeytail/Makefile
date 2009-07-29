# New ports collection makefile for:	monkeytail
# Date created:		2008-09-13
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	monkeytail
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://git.dollyfish.net.nz/releases/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A multi-file tail on both local and remote hosts

RUN_DEPENDS=	p5-IO>=0:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/Getopt/Declare.pm:${PORTSDIR}/devel/p5-Getopt-Declare

USE_PERL5_RUN=	yes

NO_BUILD=	yes

PORTDOCS=	COPYING README
PLIST_FILES=	bin/mtail

MAN1=		mtail.1
MAN5=		mtailrc.5

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mtail.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mtailrc.5 ${MAN5PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
