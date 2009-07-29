# New ports collection makefile for:	twiki-LDAPPasswordChangerPlugin
# Date created:				Wed 29 Jul 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	LDAPPasswordChangerPlugin
PORTVERSION=	0.0.${SVNREV}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Change TWiki password at a pre-configured LDAP server

RUN_DEPENDS=	${SITE_PERL}/Bundle/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

SVNREV=		18108

.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
