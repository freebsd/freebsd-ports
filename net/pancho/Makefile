# New ports collection makefile for:    pancho
# Date created:                         november 2nd, 2001
# Whom: 				Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$
#

PORTNAME=	pancho
PORTVERSION=	3.2
CATEGORIES=	net
MASTER_SITES=	http://pancho.lunarmedia.net/
DISTNAME=	pancho-v${PORTVERSION}

MAINTAINER=	Nicolas.Jombart@hsc-labs.com

RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SNMP.pm:${PORTSDIR}/net/p5-Net-SNMP

NO_BUILD=	YES

pre-everything::
.if !defined(WITH_PANCHO_LOGGING)
	@${ECHO_MSG} "Type \"make WITH_PANCHO_LOGGING=yes\" if you want to enable logging."
	@${ECHO_MSG} "Read LOGGING to know how to customize logging."
.endif

pre-patch:
	@${MV} ${WRKSRC}/pancho ${WRKSRC}/pancho.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		< ${WRKSRC}/pancho.old > ${WRKSRC}/pancho
.if defined(WITH_PANCHO_LOGGING)
	@${MV} ${WRKSRC}/pancho ${WRKSRC}/pancho.old
	@${SED} -e '35,1s:logging = "":logging = "1":' \
		< ${WRKSRC}/pancho.old > ${WRKSRC}/pancho
.endif
	@${RM} ${WRKSRC}/pancho.old

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pancho ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pancho
.for i in README LOGGING
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/pancho
.endfor
.endif

.include <bsd.port.mk>
