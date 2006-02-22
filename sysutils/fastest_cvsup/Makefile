# New ports collection makefile for:	fastest_cvsup
# Date created:        16 July 2002
# Whom:                A.J.Robinson (ajr@subdimension.com)
#
# $FreeBSD$
#

PORTNAME=	fastest_cvsup
PORTVERSION=	0.2.9
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://fastest-cvsup.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finds fastest CVSup server

DISTVERSION=	0.2.8
USE_PERL5=	yes

MAN7=		fastest_cvsup.7
PLIST_FILES=	bin/fastest_cvsup

OPTIONS=	ROUNDTRIP	"Build with round-trip patch" off

.include <bsd.port.pre.mk>

.if defined(WITH_ROUNDTRIP)
EXTRA_PATCHES=	${FILESDIR}/extrapatch-fastest_cvsup
.endif

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
