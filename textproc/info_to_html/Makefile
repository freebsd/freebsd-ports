# ex:ts=8
# New ports collection makefile for:	info_to_html
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	info_to_html
PORTVERSION=	0.9.6
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.mons.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into HTML pages

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib

PLIST_FILES=	bin/info_to_html
USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info_to_html ${PREFIX}/bin

.include <bsd.port.mk>
