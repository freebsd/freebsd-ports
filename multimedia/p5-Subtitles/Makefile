# New ports collection makefile for:	p5-Subtitles
# Date created:		2005-12-28
# Whom:			osa
#
# $FreeBSD$
#

PORTNAME=	Subtitles
PORTVERSION=	1.03
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN/Prima/KARASIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A Perl5 backend for fix subtitles timing

PERL_CONFIGURE=	5.8.0+

MAN1=	subs.1
MAN3=	Subtitles.3

.include <bsd.port.pre.mk>

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
