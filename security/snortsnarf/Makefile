# New ports collection makefile for:	snortsnarf
# Date created:		29 July 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

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

post-patch:
	@${SED} -e 's|\./include|${PREFIX}/libdata/${PORTNAME}|' \
		< ${WRKSRC}/snortsnarf.pl > ${WRKSRC}/snortsnarf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf ${LOCALBASE}/bin
	@${MKDIR} ${PREFIX}/libdata/snortsnarf
	@(cd ${WRKSRC}/include \
		&& ${COPYTREE_SHARE} . ${PREFIX}/libdata/${PORTNAME})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README Usage
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
