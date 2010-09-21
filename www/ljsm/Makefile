# New ports collection makefile for:    ljsm
# Date created:                         12 Aug 2004
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	ljsm
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	www perl5 deskutils
MASTER_SITES=	http://www.offtopia.net/ljsm/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Livejournal.com postings recusive copy utility

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PLIST_FILES=	bin/ljsm
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

EXTRACT_BEFORE_ARGS= -qoaa

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

do-configure:
	@${REINPLACE_CMD} -e 's|^#!perl|#!${PERL}|' ${WRKSRC}/ljsm.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ljsm.pl ${PREFIX}/bin/ljsm

.include <bsd.port.post.mk>
