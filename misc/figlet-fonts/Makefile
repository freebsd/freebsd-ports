# New ports collection makefile for:	figlet-fonts
# Date created:			11 August 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	figlet-fonts
PORTVERSION=	20020913
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/fonts/
DISTFILES=	contributed.tar.gz international.tar.gz

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Assorted fonts for the figlet(6) program

RUN_DEPENDS=	figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

FONTFILES!=	${CAT} ${FILESDIR}/fontfiles

do-install:
	@${INSTALL_DATA} ${FONTFILES:S/^/${WRKSRC}\//} ${PREFIX}/share/figlet

# Generate pkg-plist from files/fontfiles.

makelist:
	${CAT} ${FILESDIR}/fontfiles | ${SED} 's;^[^/]*/;share/figlet/;' \
		 > ${PLIST}

.include <bsd.port.post.mk>
