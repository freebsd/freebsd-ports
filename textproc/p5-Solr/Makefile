# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Solr
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GARAFOLA/Solr
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for interfacing with Solr

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
