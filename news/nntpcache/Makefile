PORTNAME=	nntpcache
PORTVERSION=	3.0.2
PORTREVISION=	11
CATEGORIES=	news
MASTER_SITES=	http://www.xs4all.nl/~suelette/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	News caching/anti-spam/server-merging system
WWW=		http://iq.org/~proff/nntpcache.org/

# Converted from NO_CDROM
LICENSE=	nttpcache
LICENSE_NAME=	nttpcache
LICENSE_TEXT=	Free for individuals and non-military, non-profit organisations only
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

DEPRECATED=	Upstream site no longer available
EXPIRATION_DATE=	2023-03-31
BROKEN_aarch64=		fails to link: missing sbrk
BROKEN_mips64=		fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped
BROKEN_riscv64=		fails to link: missing sbrk
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: jmp
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: jmp

USES=		compiler:c11 gmake autoreconf shebangfix
USE_RC_SUBR=	nntpcached

SHEBANG_FILES=	contrib/perlnewshound/newshound.pl

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR} \
		--program-transform-name=''

PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
PORTDOCS=	AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

OPTIONS_DEFINE=	LDAP RADIUS SPAMPHOBIA DOCS

SPAMPHOBIA_DESC=	Spamphobia NoCeM support

LDAP_USE=	OPENLDAP=yes
LDAP_CONFIGURE_WITH=	authinfo-ldap
LDAP_CPPFLAGS=	-I${PREFIX}/include -I${LOCALBASE}/include
LDAP_LDFLAGS=	-L${PREFIX}/lib -L${LOCALBASE}/lib
LDAP_VARS=	AUTHINFO_EXT+=authinfo_ldap.ext
RADIUS_CONFIGURE_WITH=	authinfo-radius
RADIUS_VARS=	AUTHINFO_EXT+=authinfo_radius.ext
SPAMPHOBIA_PATCH_SITES=	http://people.freebsd.org/~leeym/:SPAMPHOBIA
SPAMPHOBIA_PATCHFILES=	${DISTNAME}-spamphobia-${REVISEDATE}.diff.gz:SPAMPHOBIA

NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}

CPIO_CMD=	${CPIO} --quiet -pdum -R

REVISEDATE=	20060903

AUTHINFO_EXT=	authinfo_pam.ext

post-configure:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${WRKSRC}/src ${AUTHINFO_EXT}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
