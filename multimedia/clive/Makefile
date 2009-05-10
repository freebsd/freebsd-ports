# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	2.1.12
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Video extraction utility for YouTube, GoogleVideo, and others

RUN_DEPENDS=	p5-BerkeleyDB>=0.36:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA \
		p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser \
		p5-WWW-Curl>=4.05:${PORTSDIR}/www/p5-WWW-Curl

# deskutils/ljclive, multimedia/clive1 (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-1]* ljclive-[0-9]*

OPTIONS=	PASTE   "Enable pasting from X clipboard" off \
		PAGER   "Enable pager for viewing cache entries" off \
		EXPECT  "Enable clivepass interface" off \
		MANPAGE "Install manual page" on

PLIST_FILES=	bin/clive

NO_BUILD=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	5.8.2+

.include <bsd.port.pre.mk>

.if defined(WITH_PASTE)
RUN_DEPENDS+=	p5-Clipboard>=0.09:${PORTSDIR}/x11/p5-Clipboard
.endif

.if defined(WITH_PAGER)
RUN_DEPENDS+=	p5-IO-Pager>=0.06:${PORTSDIR}/devel/p5-IO-Pager
.endif

.if defined(WITH_EXPECT)
RUN_DEPENDS+=	p5-Expect>=1.21:${PORTSDIR}/lang/p5-Expect
.endif

.if defined(WITH_MANPAGE) && !defined(NO_INSTALL_MANPAGES)
MAKE_ENV=	WITH_MAN=yes
MAN1=		clive.1
.endif

.include <bsd.port.post.mk>
