# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Filter-CBC
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Source filter for Cipher Block Chaining

BUILD_DEPENDS=	p5-Filter>=0:devel/p5-Filter \
		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Crypt-CBC>=0:security/p5-Crypt-CBC
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5 shebangfix
SHEBANG_FILES=	examples/*.pl
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
