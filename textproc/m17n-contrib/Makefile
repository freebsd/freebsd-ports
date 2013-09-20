# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	m17n-contrib
PORTVERSION=	1.1.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	m17n

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	User-contributed input methods for the m17n library

BUILD_DEPENDS=	m17n-db>=1.6.4:${PORTSDIR}/devel/m17n-db
RUN_DEPENDS=	m17n-db>=1.6.4:${PORTSDIR}/devel/m17n-db

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^m17n_scriptdir = $${m17ndir}/scripts|m17n_scriptdir = ${LOCALBASE}/bin|'\
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
