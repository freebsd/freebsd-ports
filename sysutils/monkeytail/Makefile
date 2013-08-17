# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	monkeytail
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://git.dollyfish.net.nz/releases/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-file tail on both local and remote hosts

RUN_DEPENDS=	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Getopt-Declare>=0:${PORTSDIR}/devel/p5-Getopt-Declare

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
