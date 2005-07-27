# New ports collection makefile for:	Apache2-Scoreboard
# Date Created:				11 June 2005
# Whom:					Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache2-Scoreboard
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-
DISTNAME=	Apache-Scoreboard-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl interface to the Apache scoreboard structure

BUILD_DEPENDS=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Apache::Scoreboard.3 Apache::DummyScoreboard.3

INSTALLS_SHLIB=	YES

post-patch:
	@${RM} -f ${WRKSRC}/lib/Apache/*.orig
	${SED} -i.bak 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/Makefile.PL
	${SED} -i.bak 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/Dummy/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
