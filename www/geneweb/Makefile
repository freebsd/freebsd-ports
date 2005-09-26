# New ports collection makefile for:	geneweb
# Date created:				10 septembre 2005
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	geneweb
PORTVERSION=	4.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/

MAINTAINER=	hubert@frbsd.org
COMMENT=	An advanced genealogy software

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

MAN1=		ged2gwb.1 gwb2ged.1 gwc.1 gwu.1

SUB_FILES+=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${PREFIX}/share/geneweb
	${INSTALL_SCRIPT} files/install.sh ${PREFIX}/share/geneweb
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
