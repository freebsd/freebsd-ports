# New ports collection makefile for:	textproc/p5- Text-Reflow
# Date created:				2 August 2002
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Reflow
PORTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net

PERL_CONFIGURE=	yes

MAN3=		Text::Reflow.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-everything:
	@${PERL} -M5.006 -e1 2>/dev/null || \
	( ${ECHO_MSG} "===> Requires perl 5.6 or above (available from the port collection)"; \
	  ${FALSE} )

.include <bsd.port.mk>
