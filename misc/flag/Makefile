# $FreeBSD$

PORTNAME=	flag
PORTVERSION=	1.0.5
CATEGORIES=	misc
MASTER_SITES=	http://git.cyberleo.net/releases/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyberleo@cyberleo.net
COMMENT=	Turn the hostname into a colourful and visually distinctive ansi flag

NO_BUILD=	yes

OPTIONS_DEFINE=	BASH
BASH_DESC=	Install include for Bash prompt
OPTIONS_DEFAULT=BASH

PLIST_FILES=	bin/flag

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
PLIST_FILES+=	share/flag/bash_prompt.sh
PLIST_DIRS+=	share/flag
.endif

post-extract:
	${REINPLACE_CMD} -e 's@"/etc/flag"@"${PREFIX}/etc/flag"@' ${WRKSRC}/flag

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flag ${STAGEDIR}${PREFIX}/bin/flag
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bash_prompt.sh ${STAGEDIR}${DATADIR}
.endif

.include <bsd.port.mk>
