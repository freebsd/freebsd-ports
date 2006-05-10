# New ports collection makefile for:	p5-Subtitles
# Date created:		2005-12-28
# Whom:			osa
#
# $FreeBSD$
#

PORTNAME=	Subtitles
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Prima/KARASIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A Perl5 backend for fix subtitles timing

PERL_CONFIGURE=	yes

MAN1=	subs.1
MAN3=	Subtitles.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE= requires at least Perl 5.8. Install lang/perl5.8, and try again
.endif

.if defined(WITH_SUBTITLES_SUBPLAY)
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Prima.pm:${PORTSDIR}/x11-toolkits/p5-Prima \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PLIST_SUB+=	SUBPLAY=""
MAN1+=		subplay.1
.else
PLIST_SUB+=	SUBPLAY="@comment "

post-patch:
	@${REINPLACE_CMD} -e "s|\('subs'\), 'subplay'|\1|" ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
