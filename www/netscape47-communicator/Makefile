# ex:ts=8
# New ports collection makefile for:	netscape (full communicator version)
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME?=	netscape-${BROWSER_NAME}
PORTVERSION=	4.78
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_NETSCAPE}
DISTFILES=	${BROWSER_NAME}-v${PORTVERSION:S/.//g}-us.${NETSCAPE_DIST_TAG}.tar.gz

FORBIDDEN=	multiple vulnerabilities with no hope of fixes
DEPRECATED=	${FORBIDDEN}
EXPIRATION_DATE=2004-12-07

MAINTAINER=	freebsd-alpha@FreeBSD.org
COMMENT?=	Netscape version 4 communicator web-surfboard for DEC Alpha

RUN_DEPENDS+=	/compat/osf1/usr/shlib/libc.so:${PORTSDIR}/emulators/osf1_base
RUN_DEPENDS+=	netscape:${PORTSDIR}/www/netscape-wrapper

WRKSRC=		${WRKDIR}/${BROWSER_NAME}-v${PORTVERSION:S/.//g}.${NETSCAPE_DIST_TAG}
ONLY_FOR_ARCHS=	alpha
USE_XLIB=	yes
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
STRIP=		# null
#PKGDIR=	${.CURDIR}
PLIST_SUB=	BROWSER=${BROWSER_ARC} BROWSER_VER=${PORTVERSION}
MASTER_SITE_SUBDIR=	communicator/english/${PORTVERSION}/unix/supported/dec_unix40/${NETSCAPE_DIST_GRADE}

BROWSER_NAME?=	communicator
BROWSER_ARC=	${BROWSER_NAME}-osf1
.if defined(BROWSER_NAME) && ${BROWSER_NAME} == "navigator"
NETSCAPE_DIST_GRADE=	navigator_standalone
.endif
NETSCAPE_DIST_GRADE?=	complete_install
NETSCAPE_DIST_TAG=	alpha-dec-osf4.0
NDIR=		${PREFIX}/${NSUBDIR}
NSUBDIR=	lib/netscape
BINDIR=		${PREFIX}/bin
INFILE_HEAD?=	'Communicator,4.78.0.20010625'
WRAPPER_TEMPLATE=	${MASTERDIR}/files/netscape.sh
MAILCAP=	${MASTERDIR}/files/mailcap

post-configure:
	@${SED}	-e "s;@PREFIX@;${PREFIX};g" -e "s;@NSUBDIR@;${NSUBDIR};g" \
		-e "s;@BROWSER@;${BROWSER_ARC};g" \
		-e "s;@BROWSER_VER@;${PORTVERSION};g" \
		${WRAPPER_TEMPLATE} >${WRKSRC}/netscape
	@${CHMOD} +x ${WRKSRC}/netscape
	@${ECHO_CMD} -n ${INFILE_HEAD},${NDIR} >${WRKSRC}/infile

do-install:
	${MKDIR} ${NDIR}/java/classes
	for i in ${WRKSRC}/*.nif; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $${i} ${EXTRACT_AFTER_ARGS} -C ${NDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/*.jar ${NDIR}/java/classes
	${INSTALL_PROGRAM} ${WRKSRC}/vreg ${NDIR}
	${WRKSRC}/vreg ${NDIR}/registry ${WRKSRC}/infile
	${MV} -f ${NDIR}/netscape ${NDIR}/${BROWSER_ARC}-${PORTVERSION}.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/${BROWSER_ARC}-${PORTVERSION}
	${LN} -sf ${BROWSER_ARC}-${PORTVERSION} ${BINDIR}/${BROWSER_ARC}-4
	${LN} -sf ${BROWSER_ARC}-4 ${BINDIR}/netscape.run
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${MAILCAP} ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
	${CHOWN} -R root:wheel ${NDIR}

post-install:
	cd ${PREFIX} ;\
	    ${FIND} ${NSUBDIR} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.ns-lib
	cd ${PREFIX} ;\
	    ${FIND} ${NSUBDIR} -type d | \
	    	${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.ns-lib
	${ECHO_CMD} "@unexec rmdir %D/${NSUBDIR} 2>&1 || true" >> ${WRKDIR}/PLIST.ns-lib
	${CAT} ${DESCR}

.include <bsd.port.mk>
