# $FreeBSD$

PORTNAME=	poudriere
DISTVERSION=	3.1.99.20170516
PORTREVISION=	0
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME}/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	poudriere-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	3.0-2123-ga663c9c4
#DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

GNU_CONFIGURE=	yes
ETCDIR=		${PREFIX}/etc/poudriere.d

OPTIONS_DEFINE=	ZSH QEMU EXAMPLES
OPTIONS_DEFAULT=ZSH
OPTIONS_SUB=	yes

RUN_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
RUN_DEPENDS+=	freebsd-release-manifests>0:misc/freebsd-release-manifests

QEMU_DESC=	Add qemu-user-static to compile ports for non-x86 architectures
QEMU_RUN_DEPENDS=	qemu-user-static>0:emulators/qemu-user-static

.include <bsd.port.options.mk>

# rm -x support came in 10.0.  A bundled rm is used if not supported in base.
# While <10 is technically not supported in the Ports Tree, Poudriere
# detects this and it being a package build tool it should still be
# supported as a user may be installing this to build packages for upgrading
# their system to a supported release.
.if ${OSVERSION} < 1000000
PLIST_SUB+=	RM=""
.else
PLIST_SUB+=	RM="@comment "
.endif

pre-install:
	${REINPLACE_CMD} \
	    -e "s,^\(POUDRIERE_VERSION\)=.*,\1='${PKGVERSION}'," \
	    ${WRKSRC}/src/bin/poudriere

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_poudriere \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${LN} -fs ${LOCALBASE}/share/freebsd/MANIFESTS \
	    ${STAGEDIR}${DATADIR}/MANIFESTS

.include <bsd.port.mk>
