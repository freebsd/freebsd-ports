# $FreeBSD$

PORTNAME=	password-store
PORTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://git.zx2c4.com/password-store/snapshot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stores, retrieves, generates, and synchronizes passwords securely

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		getopt>=0:misc/getopt \
		gnupg>=2:security/gnupg \
		pwgen>=0:sysutils/pwgen \
		tree>=1.7:sysutils/tree

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		GIT XCLIP CONTRIB DOCS EXAMPLES
OPTIONS_SUB=		yes

GIT_DESC=		Enable git storage
XCLIP_DESC=		Enable xclip feature
CONTRIB_DESC=		Include shell completions, import scripts, related projects

GIT_RUN_DEPENDS=	git>=0:devel/git
XCLIP_RUN_DEPENDS=	base64>=0:converters/base64 \
			xclip>=0:x11/xclip

.include <bsd.port.options.mk>

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

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/password-store.sh ${STAGEDIR}${PREFIX}/libexec/pass
	@${LN} -s ${PREFIX}/libexec/pass ${STAGEDIR}${PREFIX}/bin/pass

do-install-CONTRIB-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/src/completion && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/man/example-filter.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/man/pass.1 ${STAGEDIR}${MANPREFIX}/man/man1/pass.1

.include <bsd.port.mk>
