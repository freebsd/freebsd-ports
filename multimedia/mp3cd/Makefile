# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp3cd
PORTVERSION=	1.027
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://outflux.net/software/pkgs/mp3cd/download/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Perl script that burns MP3 to audio CDs

BUILD_DEPENDS=	p5-Config-Simple>=0:${PORTSDIR}/devel/p5-Config-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	scripts/mp3cd

MAN1=	mp3cd.1
MANCOMPRESS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
