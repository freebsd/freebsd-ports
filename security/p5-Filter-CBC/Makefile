# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Filter-CBC
PORTVERSION=	0.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Source filter for Cipher Block Chaining

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
