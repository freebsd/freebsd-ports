# ex:ts=8
# New ports collection makefile for:	POE::Filter::XML
# Date created:		Aug 19, 2001
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-XML
PORTVERSION=	0.23
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	jdputsch@comcast.net
COMMENT=	A POE Filter for parsing XML

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::XML::Node.3 \
		POE::Filter::XML::Parser.3 \
		POE::Filter::XML::Utils.3 \
		POE::Filter::XML::NS.3 \
		POE::Filter::XML.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/g;' \
		-e '$$_ = "" if /warnings/' ${WRKSRC}/lib/POE/Filter/XML/NS.pm \
       		${WRKSRC}/lib/POE/Filter/XML/Node.pm ${WRKSRC}/lib/POE/Filter/XML/Handler.pm \
		${WRKSRC}/lib/POE/Filter/XML/Parser.pm ${WRKSRC}/lib/POE/Filter/XML/Meta.pm \
		${WRKSRC}/lib/POE/Filter/XML/Utils.pm ${WRKSRC}/lib/POE/Filter/XML.pm
.endif

.include <bsd.port.post.mk>
