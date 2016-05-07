# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3cd
PORTVERSION=	1.027
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://outflux.net/software/pkgs/mp3cd/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script that burns MP3 to audio CDs

LICENSE=	GPLv2+

BUILD_DEPENDS=	p5-Config-Simple>=0:devel/p5-Config-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	scripts/mp3cd
NO_ARCH=	yes

.include <bsd.port.mk>
