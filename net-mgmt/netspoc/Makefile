# Created by: ijliao
# $FreeBSD$

PORTNAME=	netspoc
PORTVERSION=	3.2
CATEGORIES=	net-mgmt
MASTER_SITES=	BERLIOS
DISTNAME=	Netspoc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Network Security Policy Compiler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.shtml ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
