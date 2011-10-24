# New ports collection makefile for: net-p2p/eiskaltdcpp-cli
# Date created:		06 Oct @011
# Whom:			Maxim Ignatenko <gelraen.ua@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-cli
PORTVERSION=	2.2.4
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Shared data for EiskaltDC++ GUIs

LICENSE=	GPLv3

RUN_DEPENDS=	p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML \
	    	p5-Term-ShellUI>=0:${PORTSDIR}/shells/p5-Term-ShellUI

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN1=	${PORTNAME}.1
MANCOMPRESSED=	no

do-install:
	@${INSTALL_SCRIPT} "${WRKSRC}/${PORTNAME}/cli.pl" "${PREFIX}/bin/eiskaltdcpp-cli"
	@${INSTALL_MAN} "${WRKSRC}/${PORTNAME}/eiskaltdcpp-cli.1" "${PREFIX}/man/man1/"
	@${MKDIR} "${PREFIX}/etc/eiskaltdcpp" || true
	@${INSTALL_DATA} "${WRKSRC}/${PORTNAME}/config.pl" "${PREFIX}/etc/eiskaltdcpp/config.pl.dist"
	@if [ ! -f "${PREFIX}/etc/eiskaltdcpp/config.pl" ]; then \
		${CP} -pv "${PREFIX}/etc/eiskaltdcpp/config.pl.dist" \
			"${PREFIX}/etc/eiskaltdcpp/config.pl"; \
	fi

.include <bsd.port.mk>
