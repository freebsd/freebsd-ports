# Created by: ijliao
# $FreeBSD$

PORTNAME=	info_to_html
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.mons.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into HTML pages

PLIST_FILES=	bin/info_to_html
USES=		perl5
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info_to_html ${PREFIX}/bin

.include <bsd.port.post.mk>
