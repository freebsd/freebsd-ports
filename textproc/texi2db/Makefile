# Created by: ijliao
# $FreeBSD$

PORTNAME=	texi2db
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tldp.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts a Texinfo file into DocBook XML

BUILD_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/texi2db ${SITE_MAN1}/${PORTNAME}.1.gz

.include <bsd.port.mk>
