# New ports collection makefile for:	bitflu
# Date created:		28 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitflu
PORTVERSION=	0.33
CATEGORIES=	net-p2p
MASTER_SITES=	http://bitflu.workaround.ch/bitflu/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	BitTorrent client written in Perl

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

PLIST_FILES=	bin/bitflu %%EXAMPLESDIR%%/bitflu.config
PLIST_DIRS=	%%EXAMPLESDIR%%
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.config.example ${EXAMPLESDIR}/${PORTNAME}.config

.include <bsd.port.mk>
