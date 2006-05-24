# New ports collection makefile for:	nntpcache
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $FreeBSD$
#

PORTNAME=	nntpcache
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.nntpcache.com/pub/nntpcache/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	News caching/anti-spam/server-merging system

USE_AUTOTOOLS=	automake:15:env

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR}

AUTHINFO_EXT=	authinfo_pam.ext
USE_RC_SUBR=	nntpcached

OPTIONS=	LDAP "OpenLDAP support" off \
		RADIUS "RADIUS support" off \
		SPAMPHOBIA "Spamphobia NoCeM support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_RADIUS)
CONFIGURE_ARGS+=	--with-authinfo-radius
AUTHINFO_EXT+=		authinfo_radius.ext
.endif

.if defined(WITH_LDAP) || defined(WITH_LDAP2)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-authinfo-ldap
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib
AUTHINFO_EXT+=	authinfo_ldap.ext
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif
CONFIGURE_ARGS+=	--program-transform-name=''

NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}
PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
CPIO_CMD=	${CPIO} --quiet -pdum -R
MAN8=		nntpcached.8 newshound.8
PORTDOCS=	AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

.if defined(WITH_SPAMPHOBIA)
PATCH_SITES+=	http://people.freebsd.org/~leeym/:SPAMPHOBIA
PATCHFILES+=	${DISTNAME}-spamphobia.diff.gz:SPAMPHOBIA
post-patch:
	${REINPLACE_CMD} -e '/nocem filter/s|logd|//logd|g' ${WRKSRC}/src/xover.c
.endif

post-configure:
	@cd ${WRKSRC}/src && ${GMAKE} ${AUTHINFO_EXT}

post-install:
	@ ${MKDIR} ${NNTPSPOOLDIR} && ${CHMOD} 750 ${NNTPSPOOLDIR}
	@ ${CP} ${PREFIX}/etc/${PORTNAME}/VERSION ${NNTPSPOOLDIR} && \
	  ${CHMOD} 640 ${NNTPSPOOLDIR}/VERSION
	@ ${CHOWN} -R news:news ${NNTPSPOOLDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${FIND} ${PORTDOCS} \
	  | ${CPIO_CMD} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
