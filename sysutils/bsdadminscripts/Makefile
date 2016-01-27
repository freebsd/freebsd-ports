# Created by: Dominic Fandrey <lon_kamikaze@gmx.de>
# $FreeBSD$

PORTNAME=	bsdadminscripts
PORTVERSION=	6.1.1
PORTREVISION=	8
CATEGORIES=	sysutils ports-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Collection of administration scripts

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

TMP?=	/tmp
VAR?=	/var

PORTDOCS=	ABOUT CHANGES INSTALL NOTES THANKS

OPTIONS_DEFINE=	DOCS

SUB_FILES=	distviper pkg_libchk pkg_upgrade uma
SUB_LIST=	TMP=${TMP} PREFIX=${PREFIX} VAR=${VAR} PORTS=${PORTSDIR}

DOCS_VARS_OFF=	EVALDOCS=-nodoc

do-install:
	cd ${WRKSRC}/src && ${SH} install.sh \
		-prefix=${STAGEDIR}${PREFIX} \
		-ports=${STAGEDIR}${PORTSDIR} \
		-distdir=${STAGEDIR}${DISTDIR} \
		-datadir=${STAGEDIR}${DATADIR} \
		${EVALDOCS}
.for n in distviper pkg_libchk pkg_upgrade uma
	${MV} ${WRKDIR}/${n} ${WRKSRC}/src
	${INSTALL_SCRIPT} ${WRKSRC}/src/${n} ${STAGEDIR}${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/buildflags.mk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/buildflags.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/uma.conf.sample ${STAGEDIR}${PREFIX}/etc

.for f in bsdadminscripts buildflags.awk buildflags.conf buildflags.mk \
	distviper pkg_libchk pkg_upgrade pkg_validate portconfig rcstart uma
	${INSTALL_MAN} ${WRKSRC}/src/${f}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/*.sample ${STAGEDIR}${ETCDIR}
	${RM} -rf ${STAGEDIR}${PREFIX}/etc/*.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
