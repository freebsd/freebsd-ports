# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-rational
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rational number library for the Pure language

LICENSE=	GPLv3

USES=		pure
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	lib/pure/rational.pure \
		lib/pure/rat_interval.pure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
