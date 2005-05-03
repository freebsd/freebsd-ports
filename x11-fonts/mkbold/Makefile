# New ports collection makefile for:   mkbold
# Date created:        4 January 2002
# Whom:			KOMATSU Shinichiro
#
# $FreeBSD$
#

PORTNAME=	mkbold
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
EXTRACT_SUFX=	.bz2

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Perl script to make BDF font bold

PREFIX?=	${X11BASE}
CONFLICTS=	mkbold-mkitalic-[0-9]*

PLIST_FILES=	bin/mkbold
USE_PERL5=	yes
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mkbold
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkbold ${PREFIX}/bin

.include <bsd.port.mk>
