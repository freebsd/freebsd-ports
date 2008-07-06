# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	2.1.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		p5-Pod-Simple>=3.04:${PORTSDIR}/textproc/p5-Pod-Simple \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3

post-patch:
	@${REINPLACE_CMD} -Ee '/(pod2man|pod2text)/d' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's/->\$$method;/->\$$method\(\);/g' ${WRKSRC}/lib/Pod/*.pm
	@${REINPLACE_CMD} -e 's/\$${char}/(\$${char})/g' ${WRKSRC}/lib/Pod/Text/*.pm
	@${FIND} ${WRKSRC} -name "*.bak" -delete

.include <bsd.port.mk>
