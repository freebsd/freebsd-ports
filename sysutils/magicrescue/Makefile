# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	magicrescue
PORTVERSION=	1.1.10
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	File recovery tool which recovers deleted files from a block device

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
USE_PERL5=	run

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	jbj

SHEBANG_FILES=	magicsort tools/*.pl tools/checkrecipe

MAKE_ENV+=	STAGEDIR=${STAGEDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/magicrescue \
		${STAGEDIR}${PREFIX}/bin/dupemap
.for f in safecat inputseek textextract
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/tools/${f}
.endfor

.include <bsd.port.mk>
