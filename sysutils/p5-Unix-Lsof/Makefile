# New ports collection makefile for:	Unix-Lsof
# Date created:				Feb  3 2009
# Whom:					George Cox <gjvc@gjvc.com>
#
# $FreeBSD$
#

PORTNAME=	Unix-Lsof
PORTVERSION=	0.0.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gjvc@gjvc.com
COMMENT=	Unix::Lsof -- a wrapper to the Unix lsof utility

BUILD_DEPENDS=	${SITE_PERL}/IPC/Run3.pm:${PORTSDIR}/devel/p5-IPC-Run3
RUN_DEPENDS=	${SITE_PERL}/IPC/Run3.pm:${PORTSDIR}/devel/p5-IPC-Run3

PERL_CONFIGURE=	yes

MAN3=		Unix::Lsof.3 Unix::Lsof::Result.3
.include <bsd.port.mk>
