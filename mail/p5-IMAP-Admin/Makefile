# Created by: Martti Kuparinen <martti.kuparinen@ericsson.com>
# $FreeBSD$

PORTNAME=	IMAP-Admin
PORTVERSION=	1.6.8
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for basic IMAP server administration

LICENSE=	ART10

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	create.pl delete.pl

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
