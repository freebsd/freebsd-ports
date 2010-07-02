# New ports collection makefile for:	pulledpork
# Date created:				01 Mai 2010
# Whom:					Olli Hauer
#
# $FreeBSD$
#

PORTNAME=	pulledpork
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ohauer@gmx.de
COMMENT=	Script to update snort-2.8+ rules

RUN_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		p5-Crypt-SSLeay>=0.57:${PORTSDIR}/security/p5-Crypt-SSLeay

#LICENSE=	GPLv2

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_DIRS=	etc/pulledpork
PLIST_FILES=	bin/pulledpork.pl \
		${PLIST_DIRS}/disablesid.conf.sample \
		${PLIST_DIRS}/dropsid.conf.sample \
		${PLIST_DIRS}/enablesid.conf.sample \
		${PLIST_DIRS}/pulledpork.conf.sample

CONFIG_DIR=	${PREFIX}/${PLIST_DIRS}
SUB_FILES=	pkg-message
SUB_LIST=	CONFIGDIR=${CONFIG_DIR}

.include <bsd.port.pre.mk>

.if (${PERL_LEVEL} < 501000)
RUN_DEPENDS+=	p5-Archive-Tar>=1.52:${PORTSDIR}/archivers/p5-Archive-Tar
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE README README.CATEGORIES README.CHANGES README.RULESET README.SHAREDOBJECTS
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" ${WRKSRC}/pulledpork.pl
	@${REINPLACE_CMD} -e 's|snort/enablesid.conf|pulledpork/enablesid.conf|g' \
		-e 's|snort/dropsid.conf|pulledpork/dropsid.conf|g' \
		-e 's|snort/disablesid.conf|pulledpork/disablesid.conf|g' \
		-e "s|/usr/local/lib/snort_dynamicrules/|${PREFIX}/etc/snort/so_rules/|g" \
		${WRKSRC}/etc/pulledpork.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pulledpork.pl ${PREFIX}/bin
	@${MKDIR} -m 750 ${CONFIG_DIR}
	# pulledpork.conf contains the snort user registration key, do not install world readable
	${INSTALL_DATA} -m 440 ${WRKSRC}/etc/pulledpork.conf ${CONFIG_DIR}/pulledpork.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/disablesid.conf ${CONFIG_DIR}/disablesid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/dropsid.conf    ${CONFIG_DIR}/dropsid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/enablesid.conf  ${CONFIG_DIR}/enablesid.conf.sample

.if !defined(NOPORTDOCS)
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
.include <bsd.port.post.mk>
