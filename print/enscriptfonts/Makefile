# New ports collection makefile for:	enscriptfonts
# Date created:			15 June, 1998
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	enscriptfonts
PORTVERSION=	0.75
CATEGORIES=	print
MASTER_SITES=	http://muuz.deadbbs.com/FreeBSD/xenscript/
DISTNAME=	enscript_fonts-0.75
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	More than 120 free- and share-ware fonts to extend enscript-1.5

# user should choose their own version
#RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript-letter

NO_WRKSUBDIR=	YES
NOMANCOMPRESS=	YES
NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKDIR}/* ${PREFIX}/share/enscript/xenscript

post-install:
	@${CAT} ${DESCR}
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
