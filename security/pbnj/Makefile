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

BUILD_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-Nmap-Parser>=0:${PORTSDIR}/security/p5-Nmap-Parser \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		nmap:${PORTSDIR}/security/nmap

USES=		perl5
USE_PERL5=	configure

MAN1=	scanpbnj.1p \
	outputpbnj.1p \
	genlist.1p

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
