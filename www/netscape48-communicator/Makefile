# New ports collection makefile for:	netscape (full communicator version)
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME?=	linux-netscape-${BROWSER_NAME}
PORTVERSION=	${BROWSER_VER}
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_NETSCAPE}
DISTFILES=	${BROWSER_NAME}-v${BROWSER_V}-us.${NETSCAPE_DIST_TAG}.tar.gz

MAINTAINER=	sada@FreeBSD.org
COMMENT?=	Netscape ver 4 communicator web-surfboard

RUN_DEPENDS+=	netscape:${PORTSDIR}/www/netscape-wrapper

WRKSRC=		${WRKDIR}/${BROWSER_NAME}-v${BROWSER_V}.${NETSCAPE_DIST_TAG}
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
STRIP=		# null
#PKGDIR=	${.CURDIR}
PLIST_SUB=	BROWSER=${BROWSER_ARC} BROWSER_VER=${BROWSER_VER} \
		NSUBDIR=${NSUBDIR}
MASTER_SITE_SUBDIR=	communicator/english/${BROWSER_VER}/unix/${NETSCAPE_DIST_ARCH}/${NETSCAPE_DIST_GRADE}

BROWSER_NAME?=	communicator
BROWSER_ARC=	${BROWSER_NAME}-linux
BROWSER_VER?=	4.8
BROWSER_V?=	48
.if defined(BROWSER_NAME) && ${BROWSER_NAME} == "navigator"
NETSCAPE_DIST_GRADE=	navigator_standalone
.endif
NETSCAPE_DIST_GRADE?=	complete_install
NETSCAPE_DIST_ARCH=	supported/linux22
NETSCAPE_DIST_TAG=	x86-unknown-linux2.2
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR=	lib/netscape-linux
BINDIR=		${PREFIX}/bin
INFILE_HEAD=	'Communicator,4.8.0.20020722'
WRAPPER_TEMPLATE=	${MASTERDIR}/files/netscape.sh
MAILCAP=	${MASTERDIR}/files/mailcap

post-configure:
	${SED}	-e "s;@PREFIX@;${PREFIX};g" -e "s;@NSUBDIR@;${NSUBDIR};g" \
		-e "s;@BROWSER@;${BROWSER_ARC};g" \
		-e "s;@BROWSER_VER@;${BROWSER_VER};g" \
		-e "s;@LOCALBASE@;${LOCALBASE};" \
		${WRAPPER_TEMPLATE} >${WRKSRC}/netscape
	${CHMOD} +x ${WRKSRC}/netscape
	${ECHO_CMD} -n ${INFILE_HEAD},${NDIR} >${WRKSRC}/infile

do-install:
	${MKDIR} ${NDIR}/java/classes
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} ${EXTRACT_AFTER_ARGS} -C ${NDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	${MV} -f ${NDIR}/netscape ${NDIR}/${BROWSER_ARC}-${BROWSER_VER}.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/${BROWSER_ARC}-${BROWSER_VER}
	${LN} -sf ${BROWSER_ARC}-${BROWSER_VER} ${BINDIR}/${BROWSER_ARC}-4
	${LN} -sf ${BROWSER_ARC}-4 ${BINDIR}/netscape.run
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${MAILCAP} ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
	${CHOWN} -R root:wheel ${NDIR}

post-install:
	${CAT} ${DESCR}

.include <bsd.port.mk>
