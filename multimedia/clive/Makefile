# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	2.2.4
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Command line video extraction tool for YouTube and others

RUN_DEPENDS=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA \
		p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser \
		p5-WWW-Curl>=4.05:${PORTSDIR}/www/p5-WWW-Curl \
		p5-Class-Singleton>=1.4:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny

# deskutils/ljclive, multimedia/clive1 (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-1]* ljclive-[0-9]*

OPTIONS=	CACHE	 "With video page cache" off \
		SIGWINCH "With resizable progressbar" on

MAN1=		clive.1

PERL_CONFIGURE=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_CACHE)
RUN_DEPENDS+=	p5-BerkeleyDB>=0.36:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if defined(WITH_SIGWINCH)
RUN_DEPENDS+=	p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey
.endif

.include <bsd.port.post.mk>
