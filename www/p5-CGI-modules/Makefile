# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-modules
PORTVERSION=	2.76
CATEGORIES=	www perl5
MASTER_SITES=	http://stein.cshl.org/WWW/software/CGI::modules/ \
		http://backpan.cpan.org/authors/id/LDS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modules for perl5, for use in writing CGI scripts

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/CGI/*.orig

.include <bsd.port.mk>
