# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	geneweb
PORTVERSION=	6.07
CATEGORIES=	www
MASTER_SITES=	http://opensource.geneanet.org/attachments/download/240/
DISTNAME=	gw-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@stangl.us
COMMENT=	Advanced genealogy software

LICENSE=	GPLv2

BROKEN=		Fails to build

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

MAKE_ENV+=	STAGEDIR=${STAGEDIR}
SUB_FILES+=	pkg-message
USE_RC_SUBR=	gwd

post-install:
	(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} distrib)
	@${INSTALL_DATA} ${WRKSRC}/etc/a.gwf ${STAGEDIR}${PREFIX}/share/geneweb
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/geneweb/distribution
	@${CP} -a ${WRKSRC}/distribution ${STAGEDIR}${PREFIX}/share/geneweb/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gwc1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/geneweb/distribution/gw/gwc1
	@${INSTALL_SCRIPT} ${FILESDIR}/install.sh ${STAGEDIR}${PREFIX}/share/geneweb

.include <bsd.port.mk>
