# Created by: Olli Hauer
# $FreeBSD$

PORTNAME=	pulledpork
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Script to update snort-2.8+ rules

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Crypt-SSLeay>=0.57:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-LWP-Protocol-https>=6.00:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_DIRSTRY=	%%ETCDIR%%
PLIST_DIRS=	%%DATADIR%%

PLIST_FILES=	bin/pulledpork.pl \
		%%ETCDIR%%/disablesid.conf.sample \
		%%ETCDIR%%/dropsid.conf.sample \
		%%ETCDIR%%/enablesid.conf.sample \
		%%ETCDIR%%/modifysid.conf.sample \
		%%ETCDIR%%/pulledpork.conf.sample \
		%%DATADIR%%/README.CONTRIB \
		%%DATADIR%%/oink-conv.pl

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	LICENSE README README.CATEGORIES README.CHANGES README.RULESET README.SHAREDOBJECTS
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" ${WRKSRC}/pulledpork.pl
	@${REINPLACE_CMD} -e 's|snort/enablesid.conf|pulledpork/enablesid.conf|g' \
		-e 's|snort/dropsid.conf|pulledpork/dropsid.conf|g' \
		-e 's|snort/disablesid.conf|pulledpork/disablesid.conf|g' \
		-e 's|snort/modifysid.conf|pulledpork/modifysid.conf|g' \
		-e "s|/usr/local/lib/snort_dynamicrules/|${PREFIX}/etc/snort/so_rules/|g" \
		${WRKSRC}/etc/pulledpork.conf
	@${REINPLACE_CMD} -e "s| /usr/bin/perl|${PERL}|" ${WRKSRC}/contrib/oink-conv.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pulledpork.pl ${PREFIX}/bin
	@${MKDIR} -m 750 ${ETCDIR}
	# pulledpork.conf contains the snort user registration key, do not install world readable
	@${INSTALL_DATA} -m 440 ${WRKSRC}/etc/pulledpork.conf ${ETCDIR}/pulledpork.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/disablesid.conf ${ETCDIR}/disablesid.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/dropsid.conf    ${ETCDIR}/dropsid.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/enablesid.conf  ${ETCDIR}/enablesid.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/modifysid.conf  ${ETCDIR}/modifysid.conf.sample
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/README.CONTRIB ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/oink-conv.pl ${DATADIR}/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/README.CATEGORIES ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/README.CHANGES ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/README.RULESET ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/README.SHAREDOBJECTS ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
