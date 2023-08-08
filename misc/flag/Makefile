PORTNAME=	flag
DISTVERSION=	1.0.6
CATEGORIES=	misc
MASTER_SITES=	https://git.cyberleo.net/releases/${PORTNAME}/

MAINTAINER=	cyberleo@cyberleo.net
COMMENT=	Turn the hostname into a colourful and visually distinctive ansi flag
WWW=		https://git.cyberleo.net/CDN/flag.git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/README.md

USES=	tar:tgz

NO_BUILD=	yes

PLIST_FILES=	bin/flag

OPTIONS_DEFINE=	BASH
OPTIONS_DEFAULT=BASH
BASH_DESC=	Install include for Bash prompt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
PLIST_FILES+=	share/flag/bash_prompt.sh
.endif

post-extract:
	${REINPLACE_CMD} -e 's@"/etc/flag"@"${PREFIX}/etc/flag"@' ${WRKSRC}/flag

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flag ${STAGEDIR}${PREFIX}/bin/flag

do-install-BASH-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bash_prompt.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
