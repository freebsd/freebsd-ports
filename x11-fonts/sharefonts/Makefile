# Created by: dburr@FreeBSD.org
# $FreeBSD$

PORTNAME=	sharefonts
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of shareware ATM fonts from the CICA archives

RESTRICTED=	Shareware.  Cannot be distributed w/o prior authorization.

NO_BUILD=	yes

FONTDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	@${MKDIR} ${FONTDIR}
	${INSTALL_DATA} ${WRKDIR}/sharefont/* ${FONTDIR}

.include <bsd.port.mk>
