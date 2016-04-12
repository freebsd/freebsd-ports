# Created by: stb
# $FreeBSD$

PORTNAME=	netatalk
PORTVERSION=	2.2.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	net print
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gmake iconv libtool perl5 tar:bzip2
USE_BDB=	46+
GNU_CONFIGURE=	yes
CPPFLAGS+=	-D_IPP_PRIVATE_STRUCTURES
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	netatalk

CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			${ICONV_CONFIGURE_BASE} \
			--with-libgcrypt-dir=${LOCALBASE} \
			--with-uams-path=${PREFIX}/libexec/netatalk-uams \
			--with-bdb=${LOCALBASE}

OPTIONS_DEFINE=	SRVLOC PAM TIMELORD KRB5 ZEROCONF LDAP SENDFILE
SRVLOC_DESC=	Service Location Protocol support
TIMELORD_DESC=	Timelord network time service
KRB5_DESC=	Kerberos V UAM
ZEROCONF_DESC=	Zeroconf (Bonjour) support
SENDFILE_DESC=	sendfile support

FILES=		AppleVolumes.default AppleVolumes.system afp_ldap.conf \
		afpd.conf netatalk.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-1* yudit-[0-9]*

.if exists(/usr/include/netatalk/ddp.h)
OPTIONS_DEFINE+=APPLETALK
OPTIONS_DEFAULT=APPLETALK
APPLETALK_DESC=	AppleTalk protocol support
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKRB5}
CONFIGURE_ARGS+=	--enable-krbV-uam
PLIST_SUB+=		NETATALKKRB5=""
.else
PLIST_SUB+=		NETATALKKRB5="@comment "
.endif

.if ${PORT_OPTIONS:MAPPLETALK}
CONFIGURE_ARGS+=	--enable-ddp
PLIST_SUB+=		APPLETALK=""
FILES+=			atalkd.conf papd.conf
.else
PLIST_SUB+=		APPLETALK="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif

.if ${PORT_OPTIONS:MSRVLOC}
CONFIGURE_ARGS+=	--enable-srvloc=${LOCALBASE}
LIB_DEPENDS+=		libslp.so:net/openslp
SUB_LIST+=		SRVLOC="slpd"
.else
SUB_LIST+=		SRVLOC=""
.endif

.if ${PORT_OPTIONS:MTIMELORD}
CONFIGURE_ARGS+=	--enable-timelord
PLIST_SUB+=		TIMELORD=""
.else
PLIST_SUB+=		TIMELORD="@comment "
.endif

.if ${PORT_OPTIONS:MZEROCONF}
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=		libavahi-client.so:net/avahi-app
USES+=			pkgconfig
SUB_LIST+=		ZEROCONF="avahi_daemon"
.else
CONFIGURE_ARGS+=	--disable-zerconf
SUB_LIST+=		ZEROCONF=""
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MSENDFILE}
CONFIGURE_ARGS+=	--enable-sendfile
.else
CONFIGURE_ARGS+=	--disable-sendfile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}| ; \
		s|%%DB_LIB%%|-l${BDB_LIB_NAME}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/nu ${STAGEDIR}${PREFIX}/bin/lp2pap.sh \
		${STAGEDIR}${PREFIX}/bin/test_parse_mtab \
		${STAGEDIR}${PREFIX}/bin/afpd-mtab.pl
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${STAGEDIR}${PREFIX}/bin/macusers
.for i in ${FILES}
	${MV} ${STAGEDIR}${PREFIX}/etc/${i} ${STAGEDIR}${PREFIX}/etc/${i}.sample
.endfor
.for i in ${LINKS}
	${LN} -sf megatron ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
