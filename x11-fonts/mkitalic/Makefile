PORTNAME=	mkitalic
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	PORTS_JP
EXTRACT_SUFX=	.bz2

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Perl script to make BDF font italic

CONFLICTS=	mkbold-mkitalic

PLIST_FILES=	bin/mkitalic
EXTRACT_CMD=	${BZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mkitalic
NO_WRKSUBDIR=	yes
USES=		shebangfix perl5 tar:bzip2
SHEBANG_FILES=	mkitalic
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkitalic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
