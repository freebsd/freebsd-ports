PORTNAME=	unfs3
DISTVERSIONPREFIX=	unfs3-
DISTVERSION=	0.9.23
CATEGORIES=	net

MAINTAINER=	fuz@fuz.su
COMMENT=	User-space implementation of the NFSv3 server specification
WWW=		https://unfs3.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=byacc

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	man/man7/tags.7.gz \
		man/man8/unfsd.8.gz \
		sbin/unfsd

OPTIONS_DEFINE=	CLUSTER_EXT
CLUSTER_EXT_DESC=	include clustering extensions
CLUSTER_EXT_CONFIGURE_ON=	--enable-cluster

.include <bsd.port.mk>
