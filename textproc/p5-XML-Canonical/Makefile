# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-Canonical
PORTVERSION=	0.10
PORTREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Implementation of Canonical XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-GDOME>=0:textproc/p5-XML-GDOME
LIB_DEPENDS=	libgdome.so:textproc/gdome2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5 pkgconfig

post-patch:
	@${REINPLACE_CMD} -e '/die "VERSION" unless /d' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/Canonical/Canonical.so

.include <bsd.port.mk>
