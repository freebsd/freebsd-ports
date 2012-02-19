# New ports collection makefile for:	p5-WWW-RobotRules
# Date created:				2011-04-14
# Whom:					Frederic Culot <culot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-RobotRules
PORTVERSION=	6.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Database of robots.txt-derived permissions

BUILD_DEPENDS=	p5-URI>=1.10:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	p5-URI>=1.10:${PORTSDIR}/net/p5-URI

CONFLICTS=	p5-libwww-5*

PERL_CONFIGURE=	yes

MAN3=		WWW::RobotRules.3 \
		WWW::RobotRules::AnyDBM_File.3

.include <bsd.port.mk>
