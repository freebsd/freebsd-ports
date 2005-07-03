# New ports collection makefile for:   	yabm
# Date created:                         15 January 2005
# Whom: 				Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	yabm
PORTVERSION=	0.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://shapeshifter.se/code/yabm/release/ \
		http://www2.shapeshifter.se/code/yabm/release/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	Yet Another Bandwidth Meter, somewhat resembles the Linux bwbar

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

SUB_FILES=	pkg-message

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/scripts/yabm.sh.sample > ${WRKSRC}/scripts/yabm.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/yabm.sh ${PREFIX}/etc/rc.d/yabm.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
