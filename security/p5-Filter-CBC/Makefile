# New ports collection makefile for:	Filter-CBC
# Date created:		11 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Filter-CBC
PORTVERSION=	0.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filter
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Source filter for Cipher Block Chaining

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Filter::CBC.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
