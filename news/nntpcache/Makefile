# New ports collection makefile for:	nntpcache
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $FreeBSD$
#

PORTNAME=	nntpcache
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/net/news/nntpcache/ \
		ftp://ftp.sbs.de/pub/news/servers/nntpcache/ \
		ftp://ftp.ntua.gr/pub/net/news/nntpcache/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/news/nntpcache/ \
		http://public.www.planetmirror.com/pub/nntpcache/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	News caching/anti-spam/server-merging system

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

.if defined(WITH_LDAP) || defined(WITH_LDAP2)
USE_OPENLDAP=	yes
.endif

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only
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

pre-everything::
.if !defined(BATCH)
	@${ECHO_MSG} "To enable LDAP support use either:"
	@${ECHO_MSG} "	WITH_LDAP - OpenLDAP support"
	@${ECHO_MSG}
	@${ECHO_MSG} "To disable radius support use WITHOUT_RADIUS"
.endif

post-configure:
	@cd ${WRKSRC}/src && ${GMAKE} ${AUTHINFO_EXT}

post-install:
	@ ${MKDIR} ${PREFIX}/etc/rc.d
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${FILESDIR}/nntpcached.rc \
	  > ${WRKDIR}/nntpcached.sh
.if !defined(BATCH)
	@ ${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/nntpcached.sh startup file"
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
