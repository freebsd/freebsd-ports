# New ports collection makefile for:	p5-Fuse
# Date created:		2006-07-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Fuse
PORTVERSION=	0.08
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DP/DPAVLIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write filesystems in Perl using FUSE

BUILD_DEPENDS=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
RUN_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
BUILD_DEPENDS+=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
USE_GNOME=	pkgconfig

MAN3=		Fuse.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from sysutils/fusefs-libs
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
