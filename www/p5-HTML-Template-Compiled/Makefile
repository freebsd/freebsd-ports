# New ports collection makefile for:	p5-HTML-Template-Compiled
# Date Created:				09 Sep 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-Compiled
PORTVERSION=	0.43
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Templating system that HTML::Template files to Perl code

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Data/TreeDumper.pm:${PORTSDIR}/devel/p5-Data-TreeDumper \
       		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Template::Compiled.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our\s+(.VERSION.+)$$/$$1/o;' \
		-e '$$_ = "" if /(no|use) warnings/;' \
		${WRKSRC}/lib/HTML/Template/Compiled.pm \
		${WRKSRC}/lib/HTML/Template/Compiled/Utils.pm \
		${WRKSRC}/lib/HTML/Template/Compiled/Plugin/DHTML.pm
.endif

.include <bsd.port.post.mk>
