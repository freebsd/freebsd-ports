# Created by: Issei Suzuki <issei@jp.FreeBSD.ORG>
# $FreeBSD$

PORTNAME=	topaz
PORTVERSION=	3.41
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command driven graph plotting system for scientists and engineers

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11
MAKEFILE=	Makefile.freebsd

NO_STAGE=	yes
post-install:
	${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${PREFIX}/bin/topaz
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
