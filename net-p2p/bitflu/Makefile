# New ports collection makefile for:	bitflu
# Date created:		28 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitflu
PORTVERSION=	0.62
CATEGORIES=	net-p2p
MASTER_SITES=	http://bitflu.workaround.ch/bitflu/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	BitTorrent client written in Perl

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

PLUGINSDIR=	${PREFIX}/lib/${PORTNAME}
USE_PERL5=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR} PLUGINSDIR=${PLUGINSDIR}
PLIST_SUB=	PLUGINSDIR=lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|'\''.bitflu.config'\''|"$$ENV{HOME}/.bitflu.config"|; \
		s|\./plugins|${PLUGINSDIR}|; s|\./workdir|$$ENV{HOME}/.bitflu.workdir|; \
		s|--config=\.bitflu.config|--config=~/.bitflu.config|' \
		${WRKSRC}/bitflu.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/fluconvert.pl \
		${PREFIX}/bin/fluconvert.pl
	${INSTALL} -d ${PLUGINSDIR}/Bitflu
	${INSTALL_DATA} ${WRKSRC}/plugins/Bitflu/*.pm ${PLUGINSDIR}/Bitflu/
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.config.example \
		${EXAMPLESDIR}/${PORTNAME}.config
.endif
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/fluconvert-README.txt \
		${DOCSDIR}/fluconvert-README.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
