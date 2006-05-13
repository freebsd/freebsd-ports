# New ports collection makefile for:    ljpms
# Date created:                         12 Aug 2004
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	ljpms
PORTVERSION=    1.2
CATEGORIES=	www perl5 deskutils
MASTER_SITES=	http://ljsm.feechki.org/
DISTFILES=	ljpms-1_2.zip

MAINTAINER=	ache@freebsd.org
COMMENT=	Livejournal.com postings mass-restore and permissions utility

RUN_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite

PLIST_FILES=	bin/ljpms
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

EXTRACT_BEFORE_ARGS= -qoaa

do-configure:
	@${REINPLACE_CMD} -e 's|^#!perl|#!${PERL}|' ${WRKSRC}/ljpms.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ljpms.pl ${PREFIX}/bin/ljpms

.include <bsd.port.mk>
