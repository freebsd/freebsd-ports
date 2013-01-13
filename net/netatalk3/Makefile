# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	3.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
    		event-2:${PORTSDIR}/devel/libevent2

LATEST_LINK=	netatalk3
USE_AUTOTOOLS=	libtool
USE_BDB=	46+
USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOME=	pkgconfig
WANT_GNOME=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	netatalk

CONFIGURE_ARGS+=	--enable-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			--with-libiconv=${LOCALBASE} \
			--with-libgcrypt-dir=${LOCALBASE} \
			--with-uams-path=${PREFIX}/libexec/netatalk-uams \
			--with-bdb=${LOCALBASE} \
			--localstatedir=/var \
			--disable-bundled-libevent \
			--with-libevent-header=${LOCALBASE}/include \
			--with-libevent-lib=${LOCALBASE}/lib/event2

OPTIONS=	PAM		"Enable PAM support" off \
		KRB5		"Enable Kerberos V UAM" off \
		ZEROCONF	"Enable Zeroconf (Bonjour) support" on \
		LDAP		"Enable LDAP support" off \
		SENDFILE	"Enable sendfile support" off \
		KERBEROS	"Enable Kerberos support" on

MAN1=		ad.1 afpldaptest.1 afppasswd.1 apple_dump.1 asip-status.pl.1 \
		dbd.1 macusers.1 \
		netatalk-config.1 uniconv.1
MAN5=		afp.conf.5 afp_signature.conf.5 afp_voluuid.conf.5
MAN8=		afpd.8 cnid_dbd.8 cnid_metad.8 netatalk.8

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-[12]* yudit-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--enable-krbV-uam
PLIST_SUB+=		NETATALKKRB5=""
.else
PLIST_SUB+=		NETATALKKRB5="@comment "
.endif

.if defined (WITH_KERBEROS)
CONFIGURE_ARGS+=	--with-kerberos
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif

.if defined (WITH_ZEROCONF)
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi-app
USE_GNOME+=		pkgconfig
SUB_LIST+=		ZEROCONF="avahi_daemon"
.else
CONFIGURE_ARGS+=	--disable-zerconf
SUB_LIST+=		ZEROCONF=""
.endif

.if defined (WITH_LDAP)
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined (WITH_SENDFILE)
CONFIGURE_ARGS+=	--enable-sendfile
.else
CONFIGURE_ARGS+=	--disable-sendfile
.endif

.if ${OSVERSION} < 800031
PLIST_SUB+=	ATFUNCS="@comment "
.else
PLIST_SUB+=	ATFUNCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}| ; \
	    	s|%%DB_LIB%%|-l${BDB_LIB_NAME}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${PREFIX}/bin/macusers
	[ -f ${PREFIX}/etc/afp.conf ] || \
		${INSTALL_DATA} -c ${PREFIX}/etc/afp.conf.dist ${PREFIX}/etc/afp.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
