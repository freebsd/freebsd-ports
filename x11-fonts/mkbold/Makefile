# New ports collection makefile for:   mkbold
# Date created:        4 January 2002
# Whom:			KOMATSU Shinichiro
#
# $FreeBSD$
#

PORTNAME=	mkbold
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
EXTRACT_SUFX=	.bz2

MAINTAINER=	koma2@ms.u-tokyo.ac.jp
COMMENT=	Perl script to make BDF font bold

PLIST_FILES=	bin/mkbold
USE_PERL5=	yes
USE_X_PREFIX=	yes
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mkbold
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkbold ${PREFIX}/bin

.include <bsd.port.mk>
