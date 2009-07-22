# New ports collection makefile for:	reportmagic
# Date created:		3 December 2000
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	reportmagic
PORTVERSION=	2.21
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.reportmagic.org/	\
		http://www.reportmagic.org.uk/	\
		http://www.reportmagic.de/	\
		http://be.reportmagic.org/
DISTNAME=	rmagic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web site statistics post-processor for Analog

USE_PERL5=	yes

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog \
		${SITE_PERL}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	YES

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Install.PL -no_modules

post-install:
	@${ECHO}
	@${ECHO} "You must agree to the [Artistic] license agreement at"
	@${ECHO} "${PREFIX}/share/doc/reportmagic/license.html before"
	@${ECHO} "using Report Magic."
	@${ECHO}

.include <bsd.port.mk>
