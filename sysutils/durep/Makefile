# New ports collection makefile for:   durep
# Date created:        14 February 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	durep
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.hibernaculum.net/download/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for monitoring disk usage in a more visual way than du

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM

USE_PERL5=	yes
MAN1=		durep.1
WWW_FILES=	durep.cgi style.css bar.png
PLIST_FILES=	bin/durep ${WWW_FILES:S,^,${WWWDIR_REL}/,}
PLIST_DIRS=	${WWWDIR_REL}
PORTDOCS=	Artistic BUGS CHANGES README THANKS

do-build:
	pod2man --center="Disk Usage Report Generator" --release="durep version ${PORTVERSION}" ${WRKSRC}/durep.pod > ${WRKSRC}/durep.1

do-install:
	${INSTALL} -d ${WWWDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/durep ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/durep.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/durep.cgi ${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/style.css ${WRKSRC}/bar.png ${WWWDIR}/
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S/^/${WRKSRC}\//} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
