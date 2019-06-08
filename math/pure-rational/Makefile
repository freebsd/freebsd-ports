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

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expiring devel/llvm35
EXPIRATION_DATE=2019-08-31

USES=		pure
NO_ARCH=	yes

PORTDOCS=	README
PLIST_FILES=	lib/pure/rational.pure \
		lib/pure/rat_interval.pure

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
