# New ports collection makefile for:		pbnj
# Date created:					July 26, 2006
# Whom:						Joshua D. Abraham <jabra@ccs.neu.edu>
#
# $FreeBSD$
#

PORTNAME=	pbnj
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A suite of tools to monitor changes on a network

BUILD_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
		${SITE_PERL}/Nmap/Parser.pm:${PORTSDIR}/security/p5-Nmap-Parser \
		${SITE_PERL}/mach/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/mach/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS=	${BUILD_DEPENDS} \
		nmap:${PORTSDIR}/security/nmap

PERL_CONFIGURE=		yes

MAN1=	scanpbnj.1p \
	outputpbnj.1p \
	genlist.1p

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
