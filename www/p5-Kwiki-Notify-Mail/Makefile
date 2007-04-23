# New ports collection makefile for:	p5-Kwiki-Notify-Mail
# Date created:				Jun 4 2005
# Whom:	      				brian
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Notify-Mail
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Send email notification of topic updates

RUN_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

DEPRECATED=		Already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
BROKEN=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Notify::Mail.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
