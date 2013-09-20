# Created by: Fredrik Lindberg <fli@shapeshifter.se>
# $FreeBSD$

PORTNAME=	yabm
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.shapeshifter.se/code/yabm/release/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	Yet Another Bandwidth Meter, somewhat resembles the Linux bwbar

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=/etc/rc.subr

SUB_FILES=	pkg-message

NO_STAGE=	yes
post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/scripts/yabm.sh.sample > ${WRKSRC}/scripts/yabm.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/yabm.sh ${PREFIX}/etc/rc.d/yabm.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
