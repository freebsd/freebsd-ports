# $FreeBSD$

PORTNAME=	password-store
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://git.zx2c4.com/password-store/snapshot/

MAINTAINER=	milki@FreeBSD.org
COMMENT=	Stores, retrieves, generates, and synchronizes passwords securely

LICENSE=	GPLv2

RUN_DEPENDS=	bash>=0:${PORTSDIR}/shells/bash \
		getopt>=0:${PORTSDIR}/misc/getopt \
		gnupg>=2:${PORTSDIR}/security/gnupg \
		pwgen>=0:${PORTSDIR}/sysutils/pwgen \
		tree>=1.7:${PORTSDIR}/sysutils/tree

OPTIONS_DEFINE=		GIT XCLIP CONTRIB DOCS EXAMPLES
OPTIONS_SUB=	yes

GIT_DESC=		Enable git storage
XCLIP_DESC=		Enable xclip feature
CONTRIB_DESC=	Include shell completions, import scripts, related projects

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	git>=0:${PORTSDIR}/devel/git
.endif

.if ${PORT_OPTIONS:MXCLIP}
RUN_DEPENDS+=	base64>=0:${PORTSDIR}/converters/base64 \
		xclip>=0:${PORTSDIR}/x11/xclip
.endif

.if ! ${PORT_OPTIONS:MGIT} && ! ${PORT_OPTIONS:MXCLIP}
EXTRA_PATCHES=	${PATCHDIR}/git+xclip.patch:-p1
.elif ! ${PORT_OPTIONS:MGIT}
EXTRA_PATCHES=	${PATCHDIR}/git.patch:-p1
.elif ! ${PORT_OPTIONS:MXCLIP}
EXTRA_PATCHES=	${PATCHDIR}/xclip.patch:-p1
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|GETOPT="getopt"|GETOPT="${LOCALBASE}/bin/getopt"|' ${WRKSRC}/src/password-store.sh
	@${REINPLACE_CMD} -Ee 's|SHRED="shred -f -z"|SHRED="rm -P -f"|' ${WRKSRC}/src/password-store.sh

# empty to skip make
do-build:

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/password-store.sh ${STAGEDIR}${PREFIX}/libexec/pass
	@${LN} -s ${PREFIX}/libexec/pass ${STAGEDIR}${PREFIX}/bin/pass

.if ${PORT_OPTIONS:MCONTRIB}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/src/completion && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.endif

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/man/example-filter.sh ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/man/pass.1 ${STAGEDIR}${MANPREFIX}/man/man1/pass.1

.include <bsd.port.mk>
