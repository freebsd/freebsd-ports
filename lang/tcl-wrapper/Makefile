# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wrapper
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang tcl
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${TX_PORT}-
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Shell wrapper for ${TX_SHELL} (${TX_PORT_U})

LICENSE=	BSD

BUILD_DEPENDS=	shc:${PORTSDIR}/misc/shc

SUB_FILES=	wrapper conf.sample pkg-message

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
USES+=		tk:run
CATEGORIES=	x11-toolkits tk
.else
USES+=		tcl:run
.endif

TX_CONF=	${TX_SHELL}.conf
TX_CONF_FULL=	${PREFIX}/etc/${TX_CONF}

PLIST_FILES=	bin/${TX_SHELL} etc/${TX_CONF}.sample

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
		TX_CONF_FULL="${TX_CONF_FULL:S/${STAGEDIR}//}"

do-build: apply-slist
	${MAKE_ENV} ${LOCALBASE}/bin/shc -r -T -f ${WRKDIR}/wrapper

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/wrapper.x ${STAGEDIR}${PREFIX}/bin/${TX_SHELL}
	${INSTALL_DATA} ${WRKDIR}/conf.sample ${STAGEDIR}${PREFIX}/etc/${TX_CONF}.sample

.include <bsd.port.mk>
