# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MogileFS-Utils
PORTVERSION=	2.29
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	MogileFS tools

BUILD_DEPENDS=	p5-MogileFS-Client>=1.16:sysutils/p5-MogileFS-Client \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|MogileFS-Utils|MogileFS::Utils|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
