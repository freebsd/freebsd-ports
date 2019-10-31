# $FreeBSD$

PORTNAME=	powerdxx
DISTVERSION=	0.4.3
CATEGORIES=	sysutils

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	CPU clock speed/frequency daemon

LICENSE=	ISCL

USES=		compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze
GH_TUPLE=	lonkamikaze:powerdxx:c555acd:powerdxx/gh-pages

USE_LDCONFIG=	yes
MAKE_ARGS=	DOCSDIR="${DOCSDIR}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/gh-pages/refman.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
