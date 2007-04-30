# New ports collection makefile for:	p5-Kwiki-VimMode
# Date created:				Feb 3 2004
# Whom:	      				clsung
#
# $FreeBSD$
#

PORTNAME=	Kwiki-VimMode
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki VimMode preformatted forms of text

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/Text/VimColor.pm:${PORTSDIR}/textproc/p5-Text-VimColor
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::VimMode.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
