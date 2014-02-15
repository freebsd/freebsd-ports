# Created by: dd
# $FreeBSD$

PORTNAME=	solitaire
PORTVERSION=	19980817
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd
DISTFILES=	sol.pl sol-test.txt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference implementation of the Solitaire encryption algorithm

USES=		perl5 shebangfix
SHEBANG_FILES=	sol.pl

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/sol.pl ${DISTDIR}/sol-test.txt ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sol.pl ${STAGEDIR}${PREFIX}/bin/solitaire
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/solitaire
	${INSTALL_DATA} ${WRKSRC}/sol.pl ${WRKSRC}/sol-test.txt \
		${STAGEDIR}${PREFIX}/share/doc/solitaire

.include <bsd.port.mk>
