# New ports collection makefile for:	cp2fwb
# Date created:			20 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	cp2fwb
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}uilder/${PORTNAME}uilder/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkpoint FW1 to Firewall Builder ruleset converter

RUN_DEPENDS=	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer

PLIST_FILES=	bin/cp2fwbuilder
USE_PERL5=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cp2fwbuilder ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
