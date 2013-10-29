# Created by: vanhu
# $FreeBSD$

# TODO: - libipsec issue ?
#       - cleanup...
#       - SYSCONFDIR
#       - $LOCALBASE/sbin/setkey Vs /usr/sbin/setkey

PORTNAME=	ipsec-tools
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	vanhu@netasq.com
COMMENT=	KAME racoon IKE daemon, ipsec-tools version

CONFLICTS=	racoon-[0-9]*

USE_RC_SUBR=	racoon
USE_OPENSSL=	yes
USE_BZIP2=	yes
USE_GCC=	any

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --sysconfdir=${PREFIX}/etc/racoon \
		--localstatedir=${STATEDIR:S/\/racoon//} \
		--with-pkgversion=freebsd-${PORTVERSION}

STATEDIR=	/var/db/racoon
SUB_LIST+=	STATEDIR=${STATEDIR}
PLIST_SUB+=	STATEDIR=${STATEDIR}

OPTIONS_DEFINE=	DEBUG IPV6 ADMINPORT STATS DPD NATT NATTF FRAG HYBRID PAM \
		RADIUS LDAP GSSAPI SAUNSPEC RC5 IDEA DOCS
OPTIONS_DEFAULT=	DEBUG DPD NATT FRAG HYBRID

ADMINPORT_DESC=	Enable Admin port
STATS_DESC=	Statistics logging function
DPD_DESC=	Dead Peer Detection
NATT_DESC=	NAT-Traversal (kernel-patch required)
NATTF_DESC=	require NAT-Traversal (fail without kernel-patch)
FRAG_DESC=	IKE fragmentation payload support
HYBRID_DESC=	Hybrid, Xauth and Mode-cfg support
SAUNSPEC_DESC=	Unspecified SA mode
RC5_DESC=	RC5 encryption (patented)
IDEA_DESC=	IDEA encryption (patented)
PAM_DESC=	PAM authentication (Xauth server)
RADIUS_DESC=	Radius authentication (Xauth server)
LDAP_DESC=	LDAP authentication (Xauth server)

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900007
EXTRA_PATCHES=	${FILESDIR}/patch8-utmp.diff
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MADMINPORT}
CONFIGURE_ARGS+=	--enable-adminport
.else
CONFIGURE_ARGS+=	--disable-adminport
.endif

.if ${PORT_OPTIONS:MSTATS}
CONFIGURE_ARGS+=	--enable-stats
.else
CONFIGURE_ARGS+=	--disable-stats
.endif

.if ${PORT_OPTIONS:MDPD}
CONFIGURE_ARGS+=	--enable-dpd
.else
CONFIGURE_ARGS+=	--disable-dpd
.endif

.if ${PORT_OPTIONS:MNATT}
.	if ${PORT_OPTIONS:MNATTF}
CONFIGURE_ARGS+=	--enable-natt=yes
.	else
CONFIGURE_ARGS+=	--enable-natt=kernel
.	endif
.else
CONFIGURE_ARGS+=	--disable-natt
.endif

.if ${PORT_OPTIONS:MFRAG}
CONFIGURE_ARGS+=	--enable-frag
.else
CONFIGURE_ARGS+=	--disable-frag
.endif

.if ${PORT_OPTIONS:MHYBRID}
CONFIGURE_ARGS+=	--enable-hybrid
.else
CONFIGURE_ARGS+=	--disable-hybrid
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-libpam
.else
CONFIGURE_ARGS+=	--without-libpam
.endif

.if ${PORT_OPTIONS:MGSSAPI}
USES+=		iconv
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if ${PORT_OPTIONS:MRADIUS}
CONFIGURE_ARGS+=	--with-libradius
.else
CONFIGURE_ARGS+=	--without-libradius
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=	--with-libldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libldap
.endif

.if ${PORT_OPTIONS:MSAUNSPEC}
CONFIGURE_ARGS+=	--enable-samode-unspec
.else
CONFIGURE_ARGS+=	--disable-samode-unspec
.endif

.if ${PORT_OPTIONS:MRC5}
CONFIGURE_ARGS+=	--enable-rc5
.else
CONFIGURE_ARGS+=	--disable-rc5
.endif

.if ${PORT_OPTIONS:MIDEA}
CONFIGURE_ARGS+=	--enable-idea
.else
CONFIGURE_ARGS+=	--disable-idea
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/racoon
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && ${ECHO_CMD} ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	@${RM} -f ${WRKSRC}/src/racoon/samples/*.in
	@${CP} -r ${WRKSRC}/src/racoon/samples/* ${STAGEDIR}/${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/racoon/doc/* ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.post.mk>
