# Created by: Pierre Guinoiseau <geekounet@poildetroll.net>
# $FreeBSD$

PORTNAME=	gcap
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool for downloading Youtube closed captions

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:devel/p5-Getopt-ArgvFile \
		p5-HTML-Parser>=3.68:www/p5-HTML-Parser \
		p5-Umph-Prompt>=0:multimedia/p5-Umph-Prompt \
		p5-XML-DOM>=1.44:textproc/p5-XML-DOM
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	bin/gcap %%PERL5_MAN1%%/gcap.1.gz

.include <bsd.port.mk>
