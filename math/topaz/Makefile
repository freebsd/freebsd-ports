# Created by: Issei Suzuki <issei@jp.FreeBSD.ORG>
# $FreeBSD$

PORTNAME=	topaz
DISTVERSION=	3_41
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command driven graph plotting system for scientists and engineers

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		ncurses readline
USE_XORG=	x11
MAKEFILE=	Makefile.freebsd

post-install:
	${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${STAGEDIR}${PREFIX}/bin/topaz
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
