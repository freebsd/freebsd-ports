# Created by: Yi-Hsuan Hsin <mhsin@mhsin.org>
# $FreeBSD$

PORTNAME=	Net-Google-Calendar
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Programmatic access to Google's Calendar API

BUILD_DEPENDS=	p5-XML-Atom>=0.37:textproc/p5-XML-Atom \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Net-Google-AuthSub>=0:net/p5-Net-Google-AuthSub
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
