# Created by: proff@suburbia.net
# $FreeBSD$

PORTNAME=	nntpcache
PORTVERSION=	3.0.2
PORTREVISION=	7
CATEGORIES=	news
MASTER_SITES=	http://www.xs4all.nl/~suelette/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	News caching/anti-spam/server-merging system

USE_AUTOTOOLS=	automake:env

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR}

AUTHINFO_EXT=	authinfo_pam.ext
USE_RC_SUBR=	nntpcached

OPTIONS_DEFINE=	LDAP RADIUS SPAMPHOBIA
SPAMPHOBIA_DESC=	Spamphobia NoCeM support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRADIUS}
CONFIGURE_ARGS+=	--with-authinfo-radius
AUTHINFO_EXT+=		authinfo_radius.ext
.endif

.if ${PORT_OPTIONS:MLDAP} || defined(WITH_LDAP2)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-authinfo-ldap
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib
AUTHINFO_EXT+=	authinfo_ldap.ext
.endif
CONFIGURE_ARGS+=	--program-transform-name=''

NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}
PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
CPIO_CMD=	${CPIO} --quiet -pdum -R
MAN8=		nntpcached.8 newshound.8
PORTDOCS=	AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

.if ${PORT_OPTIONS:MSPAMPHOBIA}
REVISEDATE=	20060903
PATCH_SITES+=	http://people.freebsd.org/~leeym/:SPAMPHOBIA
PATCHFILES+=	${DISTNAME}-spamphobia-${REVISEDATE}.diff.gz:SPAMPHOBIA
.endif

post-configure:
	${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${WRKSRC}/src ${AUTHINFO_EXT}

post-install:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${FIND} ${PORTDOCS} \
	  | ${CPIO_CMD} ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
