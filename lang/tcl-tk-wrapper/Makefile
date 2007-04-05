# Ports collection makefile for:	tcl-tk-wrapper
# Date created:			4 March 2007
# Whom:	      			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
CATEGORIES=	lang tcl84 tk84
MASTER_SITES=	# empty
PKGNAMEPREFIX=	tcl-tk-
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Shell wrapper for tclsh and wish (Tcl/Tk)

NO_BUILD=	yes

TCLTK_CONF=	${PREFIX}/etc/tcltk.conf

SUB_FILES=	tclsh wish tcltk.conf.sample pkg-message
SUB_LIST+=	ECHO_CMD="${ECHO_CMD}" GREP="${GREP}" LS="${LS}" \
		TCLTK_CONF="${TCLTK_CONF}"
PLIST_FILES=	bin/tclsh bin/wish etc/tcltk.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tclsh ${PREFIX}/bin/tclsh
	${INSTALL_SCRIPT} ${WRKDIR}/wish ${PREFIX}/bin/wish
	${INSTALL_DATA} ${WRKDIR}/tcltk.conf.sample ${PREFIX}/etc/tcltk.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
