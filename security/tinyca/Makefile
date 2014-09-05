# $FreeBSD$

PORTNAME=	tinyca
PORTVERSION=	0.7.6
CATEGORIES=	security net
MASTER_SITES=	http://opsec.eu/src/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple graphical interface to manage a small Certification Authority

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		zip:${PORTSDIR}/archivers/zip \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64

USES=		perl5 tar:xz shebangfix
USE_OPENSSL=	yes
SHEBANG_FILES=	tinyca2
NO_BUILD=	yes

DOC_FILES=	INSTALL
LIB_FILES=	CA.pm CERT.pm GUI.pm HELPERS.pm KEY.pm OpenSSL.pm REQ.pm TCONFIG.pm
LIB2_FILES=	CALLBACK.pm HELPERS.pm TCONFIG.pm WORDS.pm X509_browser.pm X509_infobox.pm

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/${PORTNAME}/GUI
	${INSTALL_DATA} ${LIB_FILES:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${SITE_PERL}/${PORTNAME}
	${INSTALL_DATA} ${LIB2_FILES:S|^|${WRKSRC}/lib/GUI/|} ${STAGEDIR}${SITE_PERL}/${PORTNAME}/GUI
	${INSTALL_DATA} ${WRKSRC}/templates/openssl.cnf ${STAGEDIR}${PREFIX}/etc/tinyca.cnf.sample
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		-e "s:%%SITE_PERL%%:${SITE_PERL}:g" \
		-e "s:%%OPENSSLBASE%%:${OPENSSLBASE}:g" \
		${WRKSRC}/tinyca2 >${WRKSRC}/tinyca.new
	${INSTALL_SCRIPT} ${WRKSRC}/tinyca.new ${STAGEDIR}${PREFIX}/bin/tinyca
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
