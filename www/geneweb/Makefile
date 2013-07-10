# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	geneweb
PORTVERSION=	6.06
CATEGORIES=	www
MASTER_SITES=	http://opensource.geneanet.org/attachments/download/211/
DISTNAME=	gw-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@stangl.us
COMMENT=	Advanced genealogy software

LICENSE=	GPLv2

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		camlp5:${PORTSDIR}/devel/ocaml-camlp5

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
BUILD_DEPENDS+=	ocaml-lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
MAKE_ENV+=	ENABLE_GUI=yes
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

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
