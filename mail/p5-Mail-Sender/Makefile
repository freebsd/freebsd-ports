# New ports collection makefile for:	p5-Mail-Sender
# Date created:				July 27th 2000
# Whom:	      				Ben Smithurst <ben@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Sender
PORTVERSION=	0.8.10
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Module for sending mails with attachments through an SMTP server

PERL_CONFIGURE=	yes

MAN3=		Mail::Sender.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

post-patch:
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi -e '$$_="" if /\bwarnings\b/' ${WRKSRC}/Sender.pm
.endif
.if defined(BATCH)
	@${PERL} -pi -e 's/res = <STDIN>;/res = "N";/' ${WRKSRC}/Config.PL
.endif

.include <bsd.port.post.mk>
