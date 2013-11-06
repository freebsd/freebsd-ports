# Created by: Stephen Farrell <steve@farrell.org>
# $FreeBSD$

PORTNAME=	tkRunIt
PORTVERSION=	0.94.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://thaumaturgy.net/~etgold/software/tkRunIt/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI app launcher with completion and history

OPTIONS_DEFINE=	EXAMPLES

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
USES+=		tk
NO_BUILD=	yes

PORTEXAMPLES=	${PORTNAME:L}
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|wish|${WISH}|g' ${WRKSRC}/runit.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/runit.tcl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/runitrc.sample ${STAGEDIR}${EXAMPLESDIR}/${PORTNAME:L}
	@${ECHO_MSG} "		"
	@${ECHO_MSG} "-------------------------------------------------------------------"
	@${ECHO_MSG} "===> Installing runitrc.sample in ${EXAMPLESDIR}/${PORTNAME:L}"
	@${ECHO_MSG} "===> Copy runitrc.sample to ~/.runitrc and modify if you wish"
	@${ECHO_MSG} "-------------------------------------------------------------------"
	@${ECHO_MSG} "		"
.endif

.include <bsd.port.mk>
