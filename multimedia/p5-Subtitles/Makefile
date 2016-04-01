# Created by: osa
# $FreeBSD$

PORTNAME=	Subtitles
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN/Prima/KARASIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Perl5 backend for fix subtitles timing

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if defined(WITH_SUBTITLES_SUBPLAY)
RUN_DEPENDS=	p5-Prima>=0:x11-toolkits/p5-Prima \
		p5-Time-HiRes>=0:devel/p5-Time-HiRes

PLIST_SUB+=	SUBPLAY=""
MAN1+=		subplay.1
.else
PLIST_SUB+=	SUBPLAY="@comment "

post-patch:
	@${REINPLACE_CMD} -e "s|\('subs'\), 'subplay'|\1|" ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
