# $FreeBSD$

PORTNAME=	dotdotpwn
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Fuzzer to discover traversal directory vulnerabilities

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-Switch>=0:lang/p5-Switch	\
		p5-libwww>=0:www/p5-libwww	\
		p5-TFTP>=0:net/p5-TFTP

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wireghoul
SHEBANG_FILES=	dotdotpwn.pl DotDotPwn/BisectionAlgorithm.pm DotDotPwn/File.pm \
		DotDotPwn/Fingerprint.pm DotDotPwn/FTP.pm DotDotPwn/HTTP.pm \
		DotDotPwn/HTTP_Url.pm DotDotPwn/Payload.pm DotDotPwn/STDOUT.pm \
		DotDotPwn/TFTP.pm DotDotPwn/TraversalEngine.pm

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	AUTHORS.txt CHANGELOG.txt EXAMPLES.txt README.txt TODO.txt

OPTIONS_DEFINE=		DOCS NMAP
OPTIONS_DEFAULT=	NMAP
OPTIONS_SUB=		yes

NMAP_DESC=	Enable OS detection feature (requires nmap)

NMAP_RUN_DEPENDS=	nmap:security/nmap

do-install:
	${INSTALL_SCRIPT}   ${WRKSRC}/dotdotpwn.pl ${STAGEDIR}${PREFIX}/bin/dotdotpwn
	${MKDIR}	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/DotDotPwn
	${MKDIR}	    ${STAGEDIR}${DATADIR}/DotDotPwn
	(cd ${WRKSRC}/DotDotPwn  && ${COPYTREE_SHARE} \*   ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/DotDotPwn)
	${INSTALL_DATA} ${WRKSRC}/DotDotPwn/User-Agents.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/payload_sample_1.txt      ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/payload_sample_2.txt      ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR}  ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
