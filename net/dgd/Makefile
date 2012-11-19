# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.4.18
CATEGORIES=	net lang games
MASTER_SITES=	http://cloud.github.com/downloads/dworkin/${PORTNAME}/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin\'s Game Driver

LICENSE=	GPLv3

OPTIONS_DEFINE=	NETWORKING CLOSURES CPLUSPLUS_COMMENTS
NETWORKING_DESC=Enable networking kfuns
CLOSURES_DESC=	Enable function pointer support
CPLUSPLUS_COMMENTS_DESC=	Allow C++ style comments in LPC
OPTIONS_DEFAULT=CPLUSPLUS_COMMENTS

USE_GMAKE=	yes

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	EXTRA_DEFINES="$(EXTRA_DEFINES)"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

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
	@cd ${WRKDIR}/dgd/ && ${FIND} . -name '*.orig' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/driver ${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/precomp ${PREFIX}/bin/precomp
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/dgd/mud.dgd \
		${PREFIX}/etc/${PORTNAME}/mud.dgd.sample
	@# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
			${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
	cd ${WRKDIR}/dgd/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
