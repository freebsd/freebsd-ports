# New ports collection makefile for:	bitflu
# Date created:		28 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitflu
PORTVERSION=	1.10
CATEGORIES=	net-p2p
MASTER_SITES=	http://bitflu.workaround.ch/bitflu/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	BitTorrent client written in Perl

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

PLUGINSDIR_BASE=lib/perl5
PLUGINSDIR=	${PLUGINSDIR_BASE}/Bitflu
USE_PERL5=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR} PLUGINSDIR=${PLUGINSDIR}
PLIST_SUB=	PLUGINSDIR=${PLUGINSDIR}

PORTDOCS=	ChangeLog.txt README.txt README_IPv6.txt

OPTIONS=	IPV6 "Enable functionality over IPv6 transport" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IPV6)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6
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
	${INSTALL_SCRIPT} ${WRKSRC}/tools/fluconvert.pl \
		${PREFIX}/bin/fluconvert.pl
	${INSTALL_SCRIPT} ${WRKSRC}/tools/dumptorrent.pl \
		${PREFIX}/bin/dumptorrent.pl
	${MKDIR} ${PREFIX}/${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/Bitflu/*.pm ${PREFIX}/${PLUGINSDIR}/
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.config.example \
		${EXAMPLESDIR}/${PORTNAME}.config
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/fluconvert-README.txt \
		${DOCSDIR}/fluconvert-README.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
