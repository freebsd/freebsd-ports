# New ports collection makefile for:	p5-HTML-TableExtract
# Date created:				October 21th 2000
# Whom:					Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-TableExtract
PORTVERSION=	2.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Extract text contained in tables within an HTML document

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		HTML::TableExtract.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-configure:
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/lib/HTML/TableExtract.pm
	${PERL} -pi -e 's/exists/defined/ if m{return 1}' ${WRKSRC}/lib/HTML/TableExtract.pm
	${PERL} -pi -e "s/'<',/'<'./" ${WRKSRC}/t/30_tree.t
	${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
