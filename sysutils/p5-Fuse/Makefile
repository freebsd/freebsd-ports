# New ports collection makefile for:	p5-Fuse
# Date created:		2006-07-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Fuse
PORTVERSION=	0.09
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DP/DPAVLIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write filesystems in Perl using FUSE

BUILD_DEPENDS=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
RUN_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
BUILD_DEPENDS+=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
PORTSCOUT=	skipv:0.09_4

USE_GNOME=	pkgconfig

MAN3=		Fuse.3

.include <bsd.port.mk>
