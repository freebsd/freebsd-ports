# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	m17n-contrib
PORTVERSION=	1.1.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	User-contributed input methods for the m17n library

BUILD_DEPENDS=	m17n-db>=1.6.3:${PORTSDIR}/devel/m17n-db
RUN_DEPENDS=	m17n-db>=1.6.3:${PORTSDIR}/devel/m17n-db

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

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
