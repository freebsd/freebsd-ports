# ex:ts=8
# New ports collection makefile for:	info_to_html
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	info_to_html
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.mons.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into HTML pages

PLIST_FILES=	bin/info_to_html
USE_PERL5=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info_to_html ${PREFIX}/bin

.include <bsd.port.post.mk>
