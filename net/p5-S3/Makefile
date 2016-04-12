# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	S3
PORTVERSION=	20071102
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	http://s3.amazonaws.com/doc/s3-example-code/
PKGNAMEPREFIX=	p5-
DISTNAME=	s3-example-perl-library

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library in Perl for working with the Amazon S3 REST interface

RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww

NO_BUILD=	yes
USES=		perl5 shebangfix zip
SHEBANG_FILES=	s3-driver.pl s3-test.pl
USE_PERL5=	run
WRKSRC=		${WRKDIR}/s3-example-libraries/perl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/S3
	${INSTALL_DATA} ${WRKSRC}/S3/* ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/S3
	${INSTALL_DATA} ${WRKSRC}/S3.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/s3-*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
