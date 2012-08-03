# Ports collection makefile for: tcl-wrapper
# Date created:			4 March 2007
# Whom:	      			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang tcl
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${TX_PORT}-
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shell wrapper for ${TX_SHELL} (${TX_PORT_U})

BUILD_DEPENDS=	shc:${PORTSDIR}/misc/shc

LICENSE=	BSD

SUB_FILES=	wrapper conf.sample pkg-message pkg-install pkg-deinstall

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

TX_SHELL=	tclsh
TX_PORT=	tcl
TX_PORT_U=	Tcl
TX_CAT=		lang

.if defined(BUILDING_TK_WRAPPER)
TX_SHELL=	wish
TX_PORT=	tk
TX_PORT_U=	Tk
TX_CAT=		x11-toolkits
USE_TK_RUN=	82+
CATEGORIES=	x11-toolkits tk
.else
USE_TCL_RUN=	82+
.endif

TX_CONF=	${TX_SHELL}.conf
TX_CONF_FULL=	${PREFIX}/etc/${TX_CONF}

PLIST_FILES=	bin/${TX_SHELL} etc/${TX_CONF}.sample

.include <bsd.port.pre.mk>

.if defined(TK_VER)
TX_VER=${TK_VER}
.else
TX_VER=${TCL_VER}
.endif

SUB_LIST+=	ECHO_CMD="${ECHO_CMD}" GREP="${GREP}" LS="${LS}" \
		CP="${CP}" RM="${RM}" MD5="${MD5} -q" \
		TX_SHELL="${TX_SHELL}" TX_SHELL_U="${TX_SHELL:U}" \
		TX_PORT="${TX_PORT}" TX_PORT_U="${TX_PORT_U}" \
		TX_CAT="${TX_CAT}" TX_VER="${TX_VER}" TX_CONF="${TX_CONF}" \
		TX_CONF_FULL="${TX_CONF_FULL}"

do-build: apply-slist
	${MAKE_ENV} ${LOCALBASE}/bin/shc -r -T -f ${WRKDIR}/wrapper

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/wrapper.x ${PREFIX}/bin/${TX_SHELL}
	${INSTALL_DATA} ${WRKDIR}/conf.sample ${PREFIX}/etc/${TX_CONF}.sample

post-install:
	@MD5SUM=`${MD5} -q ${WRKDIR}/conf.sample` && \
	${REINPLACE_CMD} -e "s|^MD5SUM=.*$$|MD5SUM=$${MD5SUM}|g" ${WRKDIR}/pkg-deinstall
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
