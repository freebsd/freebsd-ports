# New ports collection makefile for:	p5-Mail-Sender
# Date created:				July 27th 2000
# Whom:	      				Ben Smithurst <ben@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Sender
PORTVERSION=	0.7.06
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes

MAN3=		Mail::Sender.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
