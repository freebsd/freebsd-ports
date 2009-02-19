# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	2.1.5
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE \
		SF
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	legatvs@gmail.com
COMMENT=	Video extraction utility for YouTube, GoogleVideo, and others

RUN_DEPENDS=	p5-BerkeleyDB>=0.36:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA \
		p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser \
		p5-WWW-Curl>=4.05:${PORTSDIR}/www/p5-WWW-Curl \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple

# deskutils/ljclive, multimedia/clive1 (same executable/manpage/distfile name)
CONFLICTS=	*clive-[0-1]*

NO_BUILD=	yes

OPTIONS=	PASTE "Paste URLs from clipboard" off \
		CLIVEPASS "Enable login passwords" off \
		SHOW "Show cache entries" off

USE_BZIP2=	yes
USE_PERL5=	5.8.2+

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PASTE)
RUN_DEPENDS+=	p5-Clipboard>=0.09:${PORTSDIR}/x11/p5-Clipboard
.endif

.if defined(WITH_SHOW)
RUN_DEPENDS+=	p5-IO-Pager-0.06:${PORTSDIR}/devel/p5-IO-Pager
.endif

.if defined(WITH_CLIVEPASS)
RUN_DEPENDS+=	p5-Expect>=1.21:${PORTSDIR}/lang/p5-Expect
.endif

.include <bsd.port.post.mk>
