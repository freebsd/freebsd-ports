# New ports collection makefile for:	nntpcache
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $FreeBSD$
#

PORTNAME=	nntpcache
PORTVERSION=	3.0.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nntpcache.org/pub/nntpcache/ \
		ftp://ftp.nethelp.no/pub/news/ \
		ftp://ftp.netsw.org/net/news/proxy/nntpcache/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake
.if defined(WITH_LDAP) && !defined(WITH_LDAP2)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap
LIB_DEPENDS+=	lber.1:${PORTSDIR}/net/openldap
.endif
.if defined(WITH_LDAP2)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
LIB_DEPENDS+=	lber.2:${PORTSDIR}/net/openldap2
.endif

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR}

AUTHINFO_EXT=	authinfo_pam.ext
.if !defined(WITHOUT_RADIUS)
CONFIGURE_ARGS+=	--with-authinfo-radius
AUTHINFO_EXT+=		authinfo_radius.ext
.endif
.if defined(WITH_LDAP) || defined(WITH_LDAP2)
CONFIGURE_ARGS+=	--with-authinfo-ldap
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib
AUTHINFO_EXT+=	authinfo_ldap.ext
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif
CONFIGURE_ARGS+=	--program-transform-name=''

NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}
PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
CPIO=		cpio --quiet -pdum -R
MAN8=		nntpcached.8 newshound.8
DOCS=		AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

.if !defined(BATCH)
post-fetch:
	@${ECHO} "To enable LDAP support use either:"
	@${ECHO} "	WITH_LDAP - LDAP v1 support"
	@${ECHO} "	WITH_LDAP2 - LDAP v2 support"
	@${ECHO}
	@${ECHO} "To disable radius support use WITHOUT_RADIUS"
.endif

post-configure:
	@cd ${WRKSRC}/src && ${GMAKE} ${AUTHINFO_EXT}

post-install:
	@ ${MKDIR} ${PREFIX}/etc/rc.d
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${FILESDIR}/nntpcached.rc \
	  > ${WRKDIR}/nntpcached.sh
.if !defined(BATCH)
	@ ${ECHO} "Installing ${PREFIX}/etc/rc.d/nntpcached.sh startup file"
.endif
	@ ${INSTALL_SCRIPT} -m 751 ${WRKDIR}/nntpcached.sh \
	  ${PREFIX}/etc/rc.d
	@ ${MKDIR} ${NNTPSPOOLDIR} && ${CHMOD} 750 ${NNTPSPOOLDIR}
	@ ${CP} ${PREFIX}/etc/${PORTNAME}/VERSION ${NNTPSPOOLDIR} && \
	  ${CHMOD} 640 ${NNTPSPOOLDIR}/VERSION
	@ ${CHOWN} -R news:news ${NNTPSPOOLDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${FIND} ${DOCS} \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
