# New ports collection makefile for:	p5-openxpki-client-cli
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-client-cli
PORTVERSION=	0.9.850
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openxpki
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-CLI-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Command line interface for local openxpki daemon

BUILD_DEPENDS=	\
	${SITE_PERL}/Config/Std.pm:${PORTSDIR}/devel/p5-Config-Std \
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	No longer supported. Use p5-openxpki-client-html-mason instead
EXPIRES=	2008-01-05
BROKEN=		distribution is broken and no longer supported.

MAN3=	OpenXPKI::Client::CLI.3
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
