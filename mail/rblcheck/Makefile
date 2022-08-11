PORTNAME=	rblcheck
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	moro@remus.dti.ne.jp
COMMENT=	Command-line interface to Paul Vixie's RBL filter

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	logic
GH_TAGNAME=	d7eb2e5
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	rbl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rbl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/rblcheckrc.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
