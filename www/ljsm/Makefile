# New ports collection makefile for:    ljsm
# Date created:                         12 Aug 2004
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	ljsm
PORTVERSION=    2.5
PORTREVISION=	1
CATEGORIES=	www perl5 deskutils
MASTER_SITES=	http://ryzh.kiev.ua/ljsm/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@freebsd.org
COMMENT=	Livejournal.com postings recusive copy utility

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/SimpleLinkExtor.pm:${PORTSDIR}/www/p5-HTML-SimpleLinkExtor \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Unicode/MapUTF8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8

PLIST_FILES=	bin/ljsm
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

EXTRACT_BEFORE_ARGS= -qoaa

do-configure:
	@${REINPLACE_CMD} -e 's|^#!perl|#!${PERL}|' ${WRKSRC}/ljsm.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ljsm.pl ${PREFIX}/bin/ljsm

.include <bsd.port.mk>
