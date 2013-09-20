# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitflu
PORTVERSION=	1.35
CATEGORIES=	net-p2p
MASTER_SITES=	http://bitflu.workaround.ch/bitflu/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent client written in Perl

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

PLUGINSDIR_BASE=lib/perl5
PLUGINSDIR=	${PLUGINSDIR_BASE}/Bitflu
USES=		perl5
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR} PLUGINSDIR=${PLUGINSDIR}
PLIST_SUB=	PLUGINSDIR=${PLUGINSDIR}

PORTDOCS=	ChangeLog.txt README.txt README_IPv6.txt

OPTIONS_DEFINE=	IPV6 EXAMPLES DOCS
OPTIONS_DEFAULT=	IPV6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|'\''.bitflu.config'\''|"$$ENV{HOME}/.bitflu.config"|; \
		s|\./plugins|${PREFIX}/${PLUGINSDIR_BASE}|; \
		s|\./workdir|$$ENV{HOME}/.bitflu.workdir|; \
		s|--config=\.bitflu.config|--config=~/.bitflu.config|' \
		${WRKSRC}/bitflu.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${PREFIX}/${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/Bitflu/*.pm ${PREFIX}/${PLUGINSDIR}/
.if ${PORT_OPTIONS:MEXAMPLES}
	${INSTALL} -d ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.config.example \
		${EXAMPLESDIR}/${PORTNAME}.config
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
