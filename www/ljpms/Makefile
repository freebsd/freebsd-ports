# New ports collection makefile for:    ljpms
# Date created:                         12 Aug 2004
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	ljpms
PORTVERSION=	1.4
CATEGORIES=	www perl5 deskutils
MASTER_SITES=	http://www.offtopia.net/ljsm/
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Livejournal.com postings mass-restore and permissions utility

RUN_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/Digest/Perl/MD5.pm:${PORTSDIR}/security/p5-Digest-Perl-MD5

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
