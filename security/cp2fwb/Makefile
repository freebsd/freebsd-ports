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

MAINTAINER=	chris@unixpages.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cp2fwbuilder ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
