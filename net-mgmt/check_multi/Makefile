# $FreeBSD$

PORTNAME=	check_multi
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-purpose wrapper plugin for Nagios

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	flackem

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	sample_config/feed_passive/gencfg.in
GNU_CONFIGURE=	yes
NO_ARCH=	yes
CONFIGURE_ARGS=	--sysconfdir=${EXAMPLESDIR:H} \
		--libexecdir=${PREFIX}/libexec/nagios
INSTALL_TARGET=	install
TEST_TARGET=	test

PORTDOCS=	Changelog README
PORTEXAMPLES=	*
PLIST_FILES=	libexec/nagios/check_multi

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_INSTALL_TARGET=	install-config

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
