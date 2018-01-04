# $FreeBSD$

PORTNAME=	nethogs
PORTVERSION=	0.8.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Small net top tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	raboof

USES=	gmake shebangfix
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528

SHEBANG_FILES=	determineVersion.sh
bash_CMD=	/bin/sh

PLIST_FILES=	man/man8/nethogs.8.gz \
		sbin/nethogs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/nethogs

.include <bsd.port.mk>
