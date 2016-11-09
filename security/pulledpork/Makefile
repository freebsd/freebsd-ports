# Created by: Olli Hauer
# $FreeBSD$

PORTNAME=	pulledpork
PORTVERSION=	0.7.2
CATEGORIES=	security
MASTER_SITES=	GHL

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Script to update snort-2.8+ rules

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Crypt-SSLeay>=0.57:security/p5-Crypt-SSLeay \
		p5-LWP-Protocol-https>=6.00:www/p5-LWP-Protocol-https \
		p5-libwww>=0:www/p5-libwww \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${WRKSRC}/pulledpork.pl ${WRKSRC}/contrib/oink-conv.pl

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	shirkdog

OPTIONS_DEFINE=	DOCS
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^distro=FreeBSD-8.1|distro=FreeBSD-10-0|' \
		-e 's|snort/enablesid.conf|pulledpork/enablesid.conf|g' \
		-e 's|snort/dropsid.conf|pulledpork/dropsid.conf|g' \
		-e 's|snort/disablesid.conf|pulledpork/disablesid.conf|g' \
		-e 's|snort/modifysid.conf|pulledpork/modifysid.conf|g' \
		-e "s|/usr/local/lib/snort_dynamicrules/|${PREFIX}/etc/snort/so_rules/|g" \
		${WRKSRC}/etc/pulledpork.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pulledpork.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} -m 750 ${STAGEDIR}${ETCDIR}
# pulledpork.conf contains the snort user registration key, do not install world readable
	${INSTALL} -m 640 ${WRKSRC}/etc/pulledpork.conf ${STAGEDIR}${ETCDIR}/pulledpork.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/disablesid.conf ${STAGEDIR}${ETCDIR}/disablesid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/dropsid.conf    ${STAGEDIR}${ETCDIR}/dropsid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/enablesid.conf  ${STAGEDIR}${ETCDIR}/enablesid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/modifysid.conf  ${STAGEDIR}${ETCDIR}/modifysid.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/README.CONTRIB ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/oink-conv.pl ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/README.CATEGORIES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.RULESET ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.SHAREDOBJECTS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
