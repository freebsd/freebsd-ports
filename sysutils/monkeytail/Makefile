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

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

DOCS=		COPYING README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mtail.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mtailrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
