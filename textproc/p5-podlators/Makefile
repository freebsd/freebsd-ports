# New ports collection makefile for:	podlators
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	podlators
PORTVERSION=	2.4.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

PERL_CONFIGURE= yes

MAN1=		perlpodstyle.1
MAN3=		Pod::Man.3 Pod::ParseLink.3 Pod::Text.3 Pod::Text::Color.3 \
		Pod::Text::Overstrike.3 Pod::Text::Termcap.3

post-patch:
	${REINPLACE_CMD} -e '/pod2text/d;s/man1pod.*pod2man.*//' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-Pod-Simple>=3.06:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.include <bsd.port.post.mk>
