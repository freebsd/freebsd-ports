PORTNAME=	unfs3
DISTVERSION=	0.9.22
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://github.com/unfs3/unfs3/releases/download/unfs3-${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	User-space implementation of the NFSv3 server specification

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
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

post-extract:
	@${RM} ${WRKSRC}/Config/lex.yy.c

.include <bsd.port.mk>
