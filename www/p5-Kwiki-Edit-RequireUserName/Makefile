# New ports collection makefile for:	p5-Kwiki-Edit-RequireUserName
# Date created:				Jun 6 2005
# Whom:	      				brian
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Edit-RequireUserName
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Require a KwikiUserName for edits

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/Kwiki/UserName.pm:${PORTSDIR}/www/p5-Kwiki-UserName \
		${SITE_PERL}/Kwiki/UserPreferences.pm:${PORTSDIR}/www/p5-Kwiki-UserPreferences
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Edit::RequireUserName.3

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print0 | ${XARGS} -0 ${RM}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
