# New ports collection makefile for:	dhisd
# Date created:				Sun Feb 25 21:13:59 CET 2001
# Whom:					Bas Kruit <baskruit@bsltwr.dhis.org>
#
# $FreeBSD$
#

PORTNAME=		dhisd
PORTVERSION=		4.0.3
CATEGORIES=		net
MASTER_SITES=		http://bsltwr.dhis.org/ftp/pub/dhis/ \
			ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=		baskruit@bsltwr.dhis.org

DHISBASE=		${PREFIX}/dhis
DIRS=			dhis dhis/bin dhis/pid dhis/db dhis/log dhis/script
RDIRS=			dhis/bin dhis/pid dhis/db dhis/log dhis/script dhis

post-patch:
	@${ECHO} "===>   Patching Makefile"
	${PERL} -i -p -e "s^__PREFIX__^${DHISBASE}^g" ${WRKSRC}/Makefile
	@${ECHO} "===>   Patching documentation..."
	${PERL} -i -p -e "s^__PREFIX__^${DHISBASE}^g" ${WRKSRC}/INSTALL
	${PERL} -i -p -e "s^__PREFIX__^${DHISBASE}^g" ${WRKSRC}/README
	@${ECHO} "===>   Patching dhisd.h"
	${PERL} -i -p -e "s^__PREFIX__^${DHISBASE}^g" ${WRKSRC}/dhisd.h
	@${ECHO} "===>   Patching dhisd.sh"
	@${CP} ${FILESDIR}/dhisd.sh ${WRKSRC}
	${PERL} -i -p -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhisd.sh

do-install:

post-install:
.for dir in ${DIRS}
	@${MKDIR} ${PREFIX}/${dir}
	@${CHMOD} 700 ${PREFIX}/${dir}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/dhisd ${DHISBASE}/bin
	@${INSTALL_DATA} ${FILESDIR}/dhis.db ${DHISBASE}/db/dhis.db.sample
	@${ECHO} "dhis/bin/dhisd" >> ${TMPPLIST}
	@${ECHO} "dhis/db/dhis.db.sample" >> ${TMPPLIST}
	@${CHMOD} 600 ${PREFIX}/dhis/db/*
.if !exists(${PREFIX}/etc/rc.d/dhisd.sh)
	${ECHO} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh startup file."
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/dhisd.sh ${PREFIX}/etc/rc.d/dhisd.sh
	@${ECHO} "etc/rc.d/dhisd.sh" >> ${TMPPLIST}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DHISBASE}/doc
	@${INSTALL_DATA} ${WRKSRC}/README ${DHISBASE}/doc
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DHISBASE}/doc
	@${CHMOD} 755 ${DHISBASE}/doc
	@${ECHO} "dhis/doc/README" >> ${TMPPLIST}
	@${ECHO} "dhis/doc/INSTALL" >> ${TMPPLIST}
	@${ECHO} "@dirrm dhis/doc" >> ${TMPPLIST}
.endif
.for dir in ${RDIRS}
	@${ECHO} "@dirrm ${dir}" >> ${TMPPLIST}
.endfor
	@${ECHO} "--------------------------------------------------------------------------"
	@${ECHO} "Before dhisd can run, you will need configure BIND."
	@${ECHO} ""
	@${ECHO} "For more information, see the following site:"
	@${ECHO} "http://www.dhis.org/dhis/r4/server.html"
.if !defined(NOPORTDOCS)
	@${ECHO} "or ${DHISBASE}/doc/"
.endif
	@${ECHO} ""
	@${ECHO} "For information on this port, check the following site:"
	@${ECHO} "http://bsltwr.dhis.org/dhis/"
	@${ECHO} "--------------------------------------------------------------------------"

.include <bsd.port.mk>
