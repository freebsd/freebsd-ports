# New ports collection makefile for:	cp2fwb
# Date created:			20 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	cp2fwb
PORTVERSION=	0.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cp2fwbuilder
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkpoint FW1 to Firewall Builder ruleset converter

RUN_DEPENDS=	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

PLIST_FILES=	bin/cp2fwbuilder
USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cp2fwbuilder ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
