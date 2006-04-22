# New ports collection makefile for:	security/p5-Authen-Libwrap
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Authen-Libwrap
PORTVERSION=	0.20
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Authen::Libwrap - access to TCP Wrappers library

PERL_MODBUILD=	yes

MAN3=	Authen::Libwrap.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 'undef $$_ if /^\s*(?:no|use) warnings/o' ${WRKSRC}/Build.PL ${WRKSRC}/lib/Authen/Libwrap.pm
.endif

.include <bsd.port.post.mk>
