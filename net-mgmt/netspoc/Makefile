# Created by: ijliao
# $FreeBSD$

PORTNAME=	netspoc
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	BERLIOS
DISTNAME=	Netspoc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Security Policy Compiler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.shtml ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
