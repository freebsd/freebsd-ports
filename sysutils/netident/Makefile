# New ports collection makefile for: netident
# Date created:        11 March 2008
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	netident
PORTVERSION=	0.1.0
CATEGORIES=	sysutils deskutils
MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A tool for helping identify what network a machine is on

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface \
		${SITE_PERL}/Net/CIDR/Lite.pm:${PORTSDIR}/net/p5-Net-CIDR-Lite

USE_PERL5_RUN=	yes
USE_PERL5_BUILD=yes
NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}
PLIST_DIRS=	etc/netident

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

#nothing to configure
#do-configure:
#	@${ECHO} -n

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center=${PORTNAME}" user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} /var/db/netident/
	@${MKDIR} ${PREFIX}/etc/netident/

.include <bsd.port.mk>
