# New ports collection makefile for:	fastest_cvsup
# Date created:        16 July 2002
# Whom:                A.J.Robinson (ajr@subdimension.com)
#
# $FreeBSD$
#

PORTNAME=	fastest_cvsup
PORTVERSION=	0.2.8
CATEGORIES=	sysutils
MASTER_SITES=	http://fastest-cvsup.sourceforge.net/download/

MAINTAINER=	ajr@subdimension.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_PERL5=	yes

MAN7=		fastest_cvsup.7

.include <bsd.port.mk>
