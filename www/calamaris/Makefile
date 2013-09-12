# Created by: Dima Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	calamaris
PORTVERSION=	2.59
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl script to produce statistics out of Squid log files

USES=		shebangfix perl5
NO_BUILD=	yes
SHEBANG_FILES=	calamaris

MAN1=		calamaris.1

do-install:
	@ ${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1/calamaris.1
	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin/calamaris
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
