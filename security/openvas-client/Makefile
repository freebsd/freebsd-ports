# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-client
PORTVERSION=	2.0.4
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/595/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI client for OpenVAS

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libgdc.so:${PORTSDIR}/graphics/gdchart \
		libpng.so:${PORTSDIR}/graphics/png \
		libopenvas.so:${PORTSDIR}/security/openvas-libraries

USES=		gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/bin/gettext.sh,${LOCALBASE}/bin/gettext.sh,' \
		-e 's,$$localstatedir/openvas/CA,$$localstatedir/lib/openvas/private/CA,' \
		-e 's,$$sharedstatedir/openvas/CA,$$localstatedir/lib/openvas/CA,' \
		-e 's,$$localstatedir/openvas/users,$$localstatedir/lib/openvas/users,' \
		${WRKSRC}/openvasclient-mkcert.in

.if ${PORT_OPTIONS:MNLS}
post-build:
	@(cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/OpenVAS-Client
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.mk>
