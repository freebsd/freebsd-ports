# Created by: adam@veda.is
# $FreeBSD$

PORTNAME=	dgd
PORTVERSION=	1.4.22
CATEGORIES=	net lang games

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Game Driver

LICENSE=	GPLv3

OPTIONS_DEFINE=	NETWORKING CLOSURES CPLUSPLUS_COMMENTS DOCS
NETWORKING_DESC=Enable networking kfuns
CLOSURES_DESC=	Enable function pointer support
CPLUSPLUS_COMMENTS_DESC=	Allow C++ style comments in LPC
OPTIONS_DEFAULT=CPLUSPLUS_COMMENTS

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	dworkin

DIST_SUBDIR=	dgd
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	EXTRA_DEFINES="${EXTRA_DEFINES}"

PORTDOCS=	*

USERS=		mud
GROUPS=		mud

.include <bsd.port.options.mk>

EXTRA_DEFINES=

.if ${PORT_OPTIONS:MCLOSURES}
EXTRA_DEFINES+=	-DCLOSURES
.endif

.if ${PORT_OPTIONS:MCPLUSPLUS_COMMENTS}
EXTRA_DEFINES+=	-DSLASHSLASH
.endif

.if ${PORT_OPTIONS:MNETWORKING}
EXTRA_DEFINES+=	-DNETWORK_EXTENSIONS
.endif

post-patch:
	@cd ${PATCH_WRKSRC} && ${FIND} . -name '*.orig' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/driver ${STAGEDIR}${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKSRC}/bin/precomp ${STAGEDIR}${PREFIX}/bin/precomp
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/mud.dgd \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/mud.dgd.sample
	@# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
			${STAGEDIR}${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${STAGEDIR}${PREFIX}/etc/rc.d/dgd.sh.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
