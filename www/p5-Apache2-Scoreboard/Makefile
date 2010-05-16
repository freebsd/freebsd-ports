# New ports collection makefile for:	Apache2-Scoreboard
# Date Created:				11 June 2005
# Whom:					Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache2-Scoreboard
PORTVERSION=	2.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Apache-Scoreboard-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl interface to the Apache scoreboard structure

BUILD_DEPENDS=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
RUN_DEPENDS=	${BUILD_DEPENDS}

BROKEN=		does not compile

PERL_CONFIGURE=	5.8.0+

MAN3=		Apache::Scoreboard.3 Apache::DummyScoreboard.3

USE_LDCONFIG=	YES

post-patch:
	@${RM} -f ${WRKSRC}/lib/Apache/*.orig
	${SED} -i.bak 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/Makefile.PL
	${SED} -i.bak 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/Dummy/Makefile.PL

.include <bsd.port.mk>
