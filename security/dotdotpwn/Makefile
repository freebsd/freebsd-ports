# $FreeBSD$

PORTNAME=	dotdotpwn
PORTVERSION=	3.0.2
CATEGORIES=	security
MASTER_SITES=	GH

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Fuzzer to discover traversal directory vulnerabilities

LICENSE=	LGPL21

RUN_DEPENDS=	p5-Time-HiRes>=0:devel/p5-Time-HiRes \
		p5-Switch>=0:lang/p5-Switch	\
		p5-libwww>=0:www/p5-libwww	\
		p5-TFTP>=0:net/p5-TFTP

USE_GITHUB=	yes
GH_ACCOUNT=	wireghoul

OPTIONS_DEFINE=	NMAP
OPTIONS_SUB=	yes
NMAP_DESC=	ENABLE OS DETECTION FEATURE - REQUIRES NMAP
OPTIONS_DEFAULT=	NMAP

OSDETECTION_RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USES=	perl5 shebangfix

SHEBANG_FILES=	${WRKSRC}/dotdotpwn.pl ${WRKSRC}/DotDotPwn/BisectionAlgorithm.pm ${WRKSRC}/DotDotPwn/FTP.pm  ${WRKSRC}/DotDotPwn/File.pm ${WRKSRC}/DotDotPwn/Fingerprint.pm ${WRKSRC}/DotDotPwn/HTTP.pm ${WRKSRC}/DotDotPwn/HTTP_Url.pm ${WRKSRC}/DotDotPwn/Payload.pm ${WRKSRC}/DotDotPwn/STDOUT.pm  ${WRKSRC}/DotDotPwn/TFTP.pm ${WRKSRC}/DotDotPwn/TraversalEngine.pm

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README.txt  TODO.txt  CHANGELOG.txt  LICENSE.txt AUTHORS.txt EXAMPLES.txt

do-install:
	${INSTALL_SCRIPT}   ${WRKSRC}/dotdotpwn.pl ${STAGEDIR}${PREFIX}/bin/dotdotpwn
	${MKDIR} 	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/DotDotPwn
	${MKDIR}	    ${STAGEDIR}${DATADIR}/DotDotPwn
	(cd ${WRKSRC}/DotDotPwn  && ${COPYTREE_SHARE} \*   ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/DotDotPwn)
	${MKDIR}  ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DotDotPwn/User-Agents.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/payload_sample_1.txt      ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/payload_sample_2.txt      ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
