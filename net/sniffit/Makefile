# Created by: bsdx
# $FreeBSD$

PORTNAME=	sniffit
PORTVERSION=	0.3.7b
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	sniffit.0.3.7.beta

PATCH_SITES=	http://www.mavetju.org/download/adopted/
PATCHFILES=	sniffit_0.3.7.beta-10.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer program. For educational use

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sniffit.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/sniffit.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FIRST ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
