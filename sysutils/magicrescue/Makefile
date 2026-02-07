PORTNAME=	magicrescue
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.10
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	File recovery tool which recovers deleted files from a block device
WWW=		https://github.com/jbj/magicrescue/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jbj
USE_PERL5=	run

SHEBANG_FILES=	magicsort tools/*.pl tools/checkrecipe

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAKE_ENV+=	STAGEDIR=${STAGEDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/magicrescue \
		${STAGEDIR}${PREFIX}/bin/dupemap
.for f in safecat inputseek textextract
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/tools/${f}
.endfor

.include <bsd.port.mk>
