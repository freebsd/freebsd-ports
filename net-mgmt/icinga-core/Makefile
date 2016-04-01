# Created by: Chin-San Huang <chinsan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icinga-core
DISTNAME=	icinga-${PORTVERSION}

COMMENT=	Enterprise grade open source monitoring system based on Nagios

.include "${.CURDIR}/Makefile.common"

USE_RC_SUBR=	icinga

ALL_TARGET=	icinga
INSTALL_TARGET=	install-base install-basic install-config install-eventhandlers

SUB_FILES=	pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

OPTIONS_DEFINE=		IDOUTILS
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_DEFAULT=	IDOUTILS MONPLUGINS

IDOUTILS_DESC=		Enable Icinga Data Objects support

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDOUTILS}
LIB_DEPENDS+=		libdbi.so:databases/libdbi
CONFIGURE_ARGS+=	--enable-idoutils \
			--enable-ssl \
			--with-dbi-lib=${LOCALBASE}/lib \
			--with-dbi-inc=${LOCALBASE}/include
ALL_TARGET+=		idoutils
INSTALL_TARGET+=	install-idoutils
USE_OPENSSL=		yes
USE_RC_SUBR+=		ido2db
PLIST_SUB+=		IDOUTILS=""
.else
PLIST_SUB+=		IDOUTILS="@comment "
CONFIGURE_ARGS+=	--disable-idoutils
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#775#755#g; s#664#644#g' \
		${WRKSRC}/html/Makefile.in
# Use correct make(1) syntax to unbreak parallel builds
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-E 's#cd (.+) && (make|\$$\(MAKE\))#$$(MAKE) -C \1#'

pre-install:
.if ${PORT_OPTIONS:MIDOUTILS}
	@${STRIP_CMD} ${WRKSRC}/module/idoutils/src/ido2db \
		${WRKSRC}/module/idoutils/src/log2ido \
		${WRKSRC}/module/idoutils/src/idomod.so
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/idoutils/config/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/idoutils/db
	cd ${WRKSRC}/module/idoutils/config && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/idoutils/config
	cd ${WRKSRC}/module/idoutils/db && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/idoutils/db

.include <bsd.port.mk>
