# New ports collection makefile for:	reportmagic
# Date created:		3 December 2000
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	reportmagic
PORTVERSION=	2.03
CATEGORIES=	www
MASTER_SITES=	http://www.reportmagic.com/
DISTNAME=	rmagic-${PORTVERSION}

MAINTAINER=	jeremy@external.org

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles

WRKSRC=		${WRKDIR}/${DISTNAME}

pre-fetch:

	@${ECHO} -n "Report Magic will use FreeType if the GD library "
	@${ECHO} "is compiled with it in."
	@${ECHO} -n "GD is already listed as a LIB_DEPENDS, but in the "
	@${ECHO} "event that GD is already "
	@${ECHO} -n "installed *without* FreeType, you won't be able to "
	@${ECHO} "use it.  If you want"
	@${ECHO} -n "FreeType support, go (re)make ${PORTSDIR}/graphics/gd "
	@${ECHO} "with -DWITH_X11."
	@${ECHO}

do-build:

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Install.PL -no_modules

post-install:
	@${ECHO}
	@${ECHO} "You must agree to the [GPL] license agreement at"
	@${ECHO} "${PREFIX}/share/doc/reportmagic/license.html"
	@${ECHO} "before using Report Magic."
	@${ECHO}

.include <bsd.port.mk>
