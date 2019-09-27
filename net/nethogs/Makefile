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

BROKEN_i386=	non-constant-expression cannot be narrowed from type 'unsigned int' to 'time_t' (aka 'int') in initializer list

USE_GITHUB=	yes
GH_ACCOUNT=	raboof

USES=	compiler:c++11-lang gmake shebangfix

SHEBANG_FILES=	determineVersion.sh
bash_CMD=	/bin/sh

PLIST_FILES=	man/man8/nethogs.8.gz \
		sbin/nethogs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/nethogs

.include <bsd.port.mk>
