# New ports collection makefile for:	p5-XML-Simple
# Date created:				October 10th 2000
# Whom:	      				Andrew <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	XML-Simple
PORTVERSION=	2.12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Trivial API for reading and writing XML (esp config files)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		XML::Simple.3 XML::Simple::FAQ.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/5.005_03-lib::XML::Simple.pm

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-configure:
	${PERL} -pi -e 's/(\(POD2MAN_EXE\))/$$1 --lax/' ${WRKSRC}/Makefile

.endif
.include <bsd.port.post.mk>
