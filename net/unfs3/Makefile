PORTNAME=	unfs3
DISTVERSIONPREFIX=	unfs3-
DISTVERSION=	0.9.23
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	User-space implementation of the NFSv3 server specification
WWW=		https://unfs3.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	YACC=byacc

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	sbin/unfsd \
		share/man/man7/tags.7.gz \
		share/man/man8/unfsd.8.gz

OPTIONS_DEFINE=	CLUSTER_EXT
CLUSTER_EXT_DESC=	include clustering extensions
CLUSTER_EXT_CONFIGURE_ON=	--enable-cluster

.include <bsd.port.mk>
