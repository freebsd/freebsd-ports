# ex:ts=8
# New ports collection makefile for:	vshnu
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vshnu
PORTVERSION=	1.0107
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.cs.indiana.edu/~kinzler/vshnu/

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/Screen.pm:${PORTSDIR}/devel/p5-Term-Screen

# perl 5.6.0
.if ${OSVERSION} < 500007
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.post.mk>
