# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	geneweb
PORTVERSION=	6.05
CATEGORIES=	www
MASTER_SITES=	http://opensource.geneanet.org/attachments/download/190/
DISTNAME=	gw-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@stangl.us
COMMENT=	Advanced genealogy software

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		camlp5:${PORTSDIR}/devel/ocaml-camlp5

HAS_CONFIGURE=	yes

MAN1=		ged2gwb.1 gwb2ged.1 gwc.1 gwc2.1 gwu.1 gwd.1 consang.1 gwsetup.1

SUB_FILES+=	pkg-message
USE_RC_SUBR=	gwd

post-install:
	(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} distrib)
	${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${PREFIX}/share/geneweb
	${MKDIR} ${PREFIX}/share/geneweb/distribution
	${CP} -a ${WRKSRC}/distribution ${PREFIX}/share/geneweb/
	${INSTALL_SCRIPT} ${FILESDIR}/install.sh ${PREFIX}/share/geneweb
	${CHMOD} -R go+r  ${PREFIX}/share/geneweb ${_MANPAGES}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
