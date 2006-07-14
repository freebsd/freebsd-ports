# New ports collection makefile for:	p5-NNML
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	NNML
PORTVERSION=	1.14
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/U/UL/ULPFR
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A minimal NNTP server

PERL_CONFIGURE=	yes

RESTRICTED=	License unknown

MAN1=		nnmirror.1 nnsync.1 overview.1
MAN3=		NNML::Server.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS=	${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.if defined(BATCH)
CONFIGURE_ARGS+=	< /dev/null
.else
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.post.mk>
