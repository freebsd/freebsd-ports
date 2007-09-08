# New ports collection makefile for:	p5-WebService-NoPaste
# Date created:		2005-12-26
# Whom:			Gea-Suan Lin <gslin@netnews.NCTU.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WebService-NoPaste
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WebService
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A pastebin web application to upload snippets of text

BUILD_DEPENDS=	${SITE_PERL}/IO/All.pm:${PORTSDIR}/devel/p5-IO-All \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::NoPaste.3

OPTIONS=	X11	"Enable X11 Clipboard support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_X11)
BUILD_DEPENDS+=	${SITE_PERL}/Clipboard.pm:${PORTSDIR}/x11/p5-Clipboard
.else
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-lib-WebService-NoPaste.pm
.endif

post-patch:
	@${PERL} -pi -e "s|/usr/bin/perl|${PERL}|;" ${WRKSRC}/nopaste
.if !defined(WITH_X11)
	@${RM} ${WRKSRC}/lib/WebService/NoPaste.pm.orig
.endif

.include <bsd.port.post.mk>
