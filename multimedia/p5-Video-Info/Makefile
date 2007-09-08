# Ports collection makefile for:	p5-Video-Info
# Date Created:				Feb 25, 2004
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	Video-Info
PORTVERSION=	0.999
PORTREVISION=	2
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Video
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve video properties such as: height width codec fps

RUN_DEPENDS=	${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes
MANCOMPRESSED=	no

MAN3=		Video::Info.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500803
	${PERL} -pi -e '$$_="" if m{5.008|warnings}' ${WRKSRC}/Makefile.PL ${WRKSRC}/lib/Video/Info.pm
.endif

.include <bsd.port.post.mk>
