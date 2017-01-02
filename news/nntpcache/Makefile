# Created by: proff@suburbia.net
# $FreeBSD$

PORTNAME=	nntpcache
PORTVERSION=	3.0.2
PORTREVISION=	10
CATEGORIES=	news
MASTER_SITES=	http://www.xs4all.nl/~suelette/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	News caching/anti-spam/server-merging system

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		gmake autoreconf shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR} \
		--program-transform-name=''

SHEBANG_FILES=	contrib/perlnewshound/newshound.pl

AUTHINFO_EXT=	authinfo_pam.ext
USE_RC_SUBR=	nntpcached

OPTIONS_DEFINE=	LDAP RADIUS SPAMPHOBIA
SPAMPHOBIA_DESC=	Spamphobia NoCeM support

RADIUS_CONFIGURE_WITH=	authinfo-radius
RADIUS_VARS=	AUTHINFO_EXT+=authinfo_radius.ext

LDAP_USE=	OPENLDAP=yes
LDAP_CONFIGURE_WITH=	authinfo-ldap
LDAP_CPPFLAGS=	-I${PREFIX}/include -I${LOCALBASE}/include
LDAP_LDFLAGS=	-L${PREFIX}/lib -L${LOCALBASE}/lib
LDAP_VARS=	AUTHINFO_EXT+=authinfo_ldap.ext

NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}
PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
CPIO_CMD=	${CPIO} --quiet -pdum -R
PORTDOCS=	AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

REVISEDATE=	20060903
SPAMPHOBIA_PATCH_SITES=	http://people.freebsd.org/~leeym/:SPAMPHOBIA
SPAMPHOBIA_PATCHFILES=	${DISTNAME}-spamphobia-${REVISEDATE}.diff.gz:SPAMPHOBIA

post-configure:
	${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${WRKSRC}/src ${AUTHINFO_EXT}

post-install:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${FIND} ${PORTDOCS} \
	  | ${CPIO_CMD} ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
