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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finds fastest CVSup server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_PERL5=	yes

MAN7=		fastest_cvsup.7
PLIST_FILES=	bin/fastest_cvsup

.include <bsd.port.mk>
