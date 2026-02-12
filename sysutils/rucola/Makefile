PORTNAME=	rucola
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal-based markdown note manager
WWW=		https://github.com/Linus-Mussmaecher/rucola

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 CDLA20 GPLv3 ISCL \
		MIT MPL20 UNICODE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma \
		libssh2.so:security/libssh2

USES=		cargo pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Linus-Mussmaecher

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/dot_config
	(cd ${WRKSRC}/default-config && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/dot_config)

.include <bsd.port.mk>
