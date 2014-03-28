# Created by: KOMATSU Shinichiro
# $FreeBSD$

PORTNAME=	mkitalic
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
EXTRACT_SUFX=	.bz2

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Perl script to make BDF font italic

CONFLICTS=	mkbold-mkitalic-[0-9]*

PLIST_FILES=	bin/mkitalic
EXTRACT_CMD=	${BZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mkitalic
NO_WRKSUBDIR=	yes
USES=		shebangfix perl5 tar:bzip2
SHEBANG_FILES=	mkitalic

do-build:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkitalic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
