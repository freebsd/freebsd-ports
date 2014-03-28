# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snortsnarf
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Initial%20Release%20${PORTVERSION}
DISTNAME=	SnortSnarf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate HTML report summaries from snort incident alerts

RUN_DEPENDS=	p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules

USES=		perl5
NO_BUILD=	yes
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS

post-patch:
	@${SED} -e 's|\./include|${PREFIX}/libdata/${PORTNAME}|' \
		< ${WRKSRC}/snortsnarf.pl > ${WRKSRC}/snortsnarf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/snortsnarf
	(cd ${WRKSRC}/include \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/libdata/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README Usage
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
