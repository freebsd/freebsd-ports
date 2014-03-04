# Created by: ijliao
# $FreeBSD$

PORTNAME=	texi2db
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.tldp.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts a Texinfo file into DocBook XML

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/texi2db \
		${SITE_PERL_REL}/${PERL_ARCH}/auto/texi2db/.packlist \
		man/man1/${PORTNAME}.1.gz
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/texi2db

.include <bsd.port.mk>
