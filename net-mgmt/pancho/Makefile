# New ports collection makefile for:    pancho
# Date created:                         november 2nd, 2001
# Whom: 				Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$
#

PORTNAME=	pancho
PORTVERSION=	7.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.panchoproject.org/archives/pancho/
DISTNAME=	pancho-v${PORTVERSION}

MAINTAINER=	Nicolas.Jombart@hsc-labs.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SNMP.pm:${PORTSDIR}/net/p5-Net-SNMP \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parallel/ForkManager.pm:${PORTSDIR}/devel/p5-Parallel-ForkManager

USE_PERL5=	YES
NO_BUILD=	YES

pre-patch:
	@${CHMOD} u+w ${WRKSRC}/pancho
	@${MV} ${WRKSRC}/pancho ${WRKSRC}/pancho.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		< ${WRKSRC}/pancho.old > ${WRKSRC}/pancho
	@${RM} ${WRKSRC}/pancho.old
	@${MV} ${WRKSRC}/pancho ${WRKSRC}/pancho.old
	@${SED} -e '28,1s:pancho.conf:${PREFIX}/etc/pancho.conf:' \
		< ${WRKSRC}/pancho.old > ${WRKSRC}/pancho
	@${RM} ${WRKSRC}/pancho.old

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pancho ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/samples/sample.conf ${PREFIX}/etc/pancho.conf.sample

.include <bsd.port.mk>
