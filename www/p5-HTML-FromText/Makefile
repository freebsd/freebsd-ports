# New ports collection makefile for:	HTML::FromText
# Date created:				04 November 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		HTML-FromText
PORTVERSION=		2.05
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca
COMMENT=	Mark up text as HTML

BUILD_DEPENDS=	${SITE_PERL}/Email/Find.pm:${PORTSDIR}/mail/p5-Email-Find \
		${SITE_PERL}/Exporter/Lite.pm:${PORTSDIR}/devel/p5-Exporter-Lite \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN1=			text2html.1
MAN3=			HTML::FromText.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/_ foreach/_() foreach/' ${WRKSRC}/lib/HTML/FromText.pm
.endif

.include <bsd.port.post.mk>
