# New ports collection makefile for:	p5-Email-MIME-Encodings
# Date created:				September 7 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Encodings
PORTVERSION=	1.1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	A unified interface to MIME encoding and decoding

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME::Encodings.3

post-patch:
	${PERL} -pi -e '$$_="" if /use warnings/;' ${WRKSRC}/Encodings.pm
test:
	cd ${WRKSRC} ; make test

.include <bsd.port.mk>
