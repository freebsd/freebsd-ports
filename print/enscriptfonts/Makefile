# New ports collection makefile for:	enscriptfonts
# Version required:     	0.75
# Date created:			15 June, 1998
# Whom:				kline
#
# $Id$
#

DISTNAME=	enscript_fonts-0.75
PKGNAME=	enscriptfonts-0.75
CATEGORIES=	print
MASTER_SITES=	ftp://peloton.physics.montana.edu/pub/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kline@thought.org

RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript

NO_WRKSUBDIR=	YES
NOMANCOMPRESS=	YES
NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKDIR}/* ${PREFIX}/share/enscript/xenscript

post-install:
	@${CAT} ${PKGDIR}/DESCR
	@sleep 2;
	@${ECHO_MSG} "";
	@${ECHO_MSG} "";
	@${ECHO_MSG} "";
	@${ECHO_MSG} "Now you *must* add the path "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/share/enscript/xenscript"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "to your ${PREFIX}/etc/enscript.cfg path"
	@${ECHO_MSG} "AFMPATH configuration.  This line is somewhere"
	@${ECHO_MSG} "around line +32 in the enscript.cfg file."
	@${ECHO_MSG} "";
	@${ECHO_MSG} "";
	@${ECHO_MSG} "";

.include <bsd.port.mk>
