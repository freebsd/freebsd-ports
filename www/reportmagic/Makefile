# New ports collection makefile for:	reportmagic
# Date created:		3 December 2000
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	reportmagic
PORTVERSION=	2.13
CATEGORIES=	www
MASTER_SITES=	http://www.reportmagic.com/	\
		http://www.reportmagic.org.uk/	\
		http://www.reportmagic.de/	\
		http://be.reportmagic.org/
DISTNAME=	rmagic-${PORTVERSION}

MAINTAINER=	jeremy@external.org

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles

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
