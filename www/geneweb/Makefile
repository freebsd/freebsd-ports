# New ports collection makefile for:	geneweb
# Date created:				10 septembre 2005
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	geneweb
PORTVERSION=	5.01
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubert@frbsd.org
COMMENT=	An advanced genealogy software

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		camlp5:${PORTSDIR}/devel/ocaml-camlp5

BROKEN=		does not build

HAS_CONFIGURE=	yes

MAN1=		ged2gwb.1 gwb2ged.1 gwc.1 gwc2.1 gwu.1 gwd.1 consang.1 gwsetup.1

SUB_FILES+=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${PREFIX}/share/geneweb
	${INSTALL_SCRIPT} ${FILESDIR}/install.sh ${PREFIX}/share/geneweb
	${CHMOD} -R go+r  ${PREFIX}/share/geneweb ${_MANPAGES}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
