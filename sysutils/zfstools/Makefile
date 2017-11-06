# $FreeBSD$

PORTNAME=	zfstools
DISTVERSIONPREFIX=v
DISTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	GH \
		http://mirror.shatow.net/freebsd/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	OpenSolaris-compatible auto snapshotting for ZFS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		shebangfix
SHEBANG_FILES=	bin/*

USE_GITHUB=	yes
GH_ACCOUNT=	bdrewery

USE_RUBY=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin
	@cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
