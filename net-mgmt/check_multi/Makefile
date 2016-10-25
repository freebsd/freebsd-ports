# $FreeBSD$

PORTNAME=	check_multi
PORTVERSION=	0.26
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-purpose wrapper plugin for Nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5
GNU_CONFIGURE=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flackem

CONFIGURE_ARGS=	--sysconfdir=${EXAMPLESDIR:H} \
		--libexecdir=${PREFIX}/libexec/nagios

INSTALL_TARGET=	install
TEST_TARGET=	test

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_INSTALL_TARGET=	install-config

PORTDOCS=	Changelog README
PORTEXAMPLES=	*

PLIST_FILES=	libexec/nagios/check_multi

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
