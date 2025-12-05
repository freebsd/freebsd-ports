PORTNAME=	opkssh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Tool which enables SSH to be used with OpenID Connect

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	openpubkey
GO_BUILDFLAGS=	-ldflags "-X main.Version=${DISTVERSIONPREFIX}${DISTVERSION}"

SUB_FILES=	pkg-message
SUB_LIST=	GROUP=${OPKSSH_GROUP} \
		USER=${OPKSSH_USER}

USERS=		${OPKSSH_USER}
GROUPS=		${OPKSSH_GROUP}

PLIST_FILES=	bin/${PORTNAME}

OPKSSH_USER=	opksshuser
OPKSSH_GROUP=	${OPKSSH_USER}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor

# To generate the following patches:
#   - make extract
#   - cd ${WRKSRC}
#   - rg '/etc' | cut -d: -f1 | sort | uniq | grep -Ee '.+\.go$' | grep -vEe '_test\.go$' | xargs -I % cp % %.orig
#   - rg '/etc' | cut -d: -f1 | sort | uniq | grep -Ee '.+\.go$' | grep -vEe '_test\.go$' | xargs -L1 sed -i '' -Ee 's,/etc,%%PREFIX%%/etc,g'
#   - cd -
#   - make makepatch
#   - rm ${FILESDIR}/files/patch-vendor_g*
#   - Some replaced strings are just comments, so it's ok to leave them there,
#     but I'll remove them anyway to avoid unnecessary patches, so check each
#     file in FILESDIR.
post-patch:
	@${GREP} -Flr %%PREFIX%% ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
