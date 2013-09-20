# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	reportmagic
PORTVERSION=	2.21
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.reportmagic.org/	\
		http://www.reportmagic.org.uk/	\
		http://www.reportmagic.de/	\
		http://be.reportmagic.org/
DISTNAME=	rmagic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web site statistics post-processor for Analog

USES=		perl5

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog \
		p5-GD-Graph3d>=0:${PORTSDIR}/graphics/p5-GD-Graph3d \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	YES

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Install.PL -no_modules

post-install:
	@${ECHO}
	@${ECHO} "You must agree to the [Artistic] license agreement at"
	@${ECHO} "${PREFIX}/share/doc/reportmagic/license.html before"
	@${ECHO} "using Report Magic."
	@${ECHO}

.include <bsd.port.mk>
