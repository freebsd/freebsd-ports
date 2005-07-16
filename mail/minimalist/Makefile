# New ports collection makefile for:   minimalist
# Date created:        15 September 1999
# Whom:                gmarco@scotty.masternet.it
#
# $FreeBSD$
#

PORTNAME=	minimalist
PORTVERSION=	2.5.3
CATEGORIES=	mail
MASTER_SITES=	http://www.mml.org.ua/LIST/ \
		http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-/}

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	A minimalistic mailing list manager

USE_PERL5_RUN=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
EXTRA_SUB_FILES=docs/README minimalist.conf-sample minimalist.pl \
		contrib/minimalist_request.pl

post-patch:
	@(cd ${WRKSRC}; ${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},;s,#!/bin/perl,${PERL},;s,--fqdn,,;s,/usr/lib/sendmail,/usr/sbin/sendmail,' ${EXTRA_SUB_FILES})

do-install:
	@${MKDIR} ${PREFIX}/share/minimalist/FAQ
	@${MKDIR} ${PREFIX}/share/minimalist/FAQ
	@${MKDIR} ${PREFIX}/share/minimalist/sample
	@${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl ${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/minimalist_request.pl ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample ${PREFIX}/share/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample ${PREFIX}/etc/minimalist.conf-sample
	@${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.txt ${PREFIX}/share/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${PREFIX}/share/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/docs/virtual-domains.txt ${PREFIX}/share/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/docs/FAQ/* ${PREFIX}/share/minimalist/FAQ/
	@${INSTALL_DATA} ${WRKSRC}/sample/lists.lst ${PREFIX}/share/minimalist/list.lst-sample
	@${INSTALL_DATA} ${WRKSRC}/sample/sample/* ${PREFIX}/share/minimalist/sample/
	@${ECHO_MSG} "-------------------------------------------------------------------"
	@${ECHO_MSG} "Minimalist files are in: ${PREFIX}/share/minimalist"
	@${ECHO_MSG} "Minimalist binary is: ${PREFIX}/bin/minimalist.pl"
	@${ECHO_MSG} "Minimalist main config is: ${PREFIX}/etc/minimalist.conf-sample"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To finish the installation: "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Edit the ${PREFIX}/etc/minimalist.conf-sample and then copy "
	@${ECHO_MSG} "or rename it to ${PREFIX}/etc/minimalist.conf"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Check the ${PREFIX}/share/minimalist/README file to know how to modify"
	@${ECHO_MSG} "aliases file"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A sample configuration for a mailing list can be"
	@${ECHO_MSG} "found in ${PREFIX}/share/minimalist/sample."
	@${ECHO_MSG} "-------------------------------------------------------------------"

.include <bsd.port.mk>
