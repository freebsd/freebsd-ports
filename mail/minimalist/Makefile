# New ports collection makefile for:   minimalist
# Date created:        15 September 1999
# Whom:                gmarco@scotty.masternet.it
#
# $FreeBSD$
#

PORTNAME=	minimalist
PORTVERSION=	2.2.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mml.org.ua/pub/minimalist/ \
		http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g:S/-/./}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gmarco@giovannelli.it

NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@(cd ${WRKSRC}; ${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' README \
		minimalist.conf-sample minimalist.pl)

do-install:
	@${MKDIR} ${PREFIX}/minimalist/sample
	@${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${PREFIX}/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample ${PREFIX}/minimalist
	@${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample ${PREFIX}/etc/minimalist.conf-sample
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/sample/lists.lst ${PREFIX}/minimalist/
	@${INSTALL_DATA} ${WRKSRC}/sample/sample/* ${PREFIX}/minimalist/sample/
	@${ECHO_MSG} "-------------------------------------------------------------------"
	@${ECHO_MSG} "Minimalist files are in: ${PREFIX}/minimalist"
	@${ECHO_MSG} "Minimalist binary is: ${PREFIX}/bin/minimalist.pl"
	@${ECHO_MSG} "Minimalist main config is: ${PREFIX}/etc/minimalist.conf-sample"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To finish the installation: "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Edit the ${PREFIX}/etc/minimalist.conf-sample and then copy "
	@${ECHO_MSG} "or rename it to ${PREFIX}/etc/minimalist.conf"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Check the ${PREFIX}/minimalist/README file to know how to modify"
	@${ECHO_MSG} "aliases file"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A sample configuration for a mailing list can be"
	@${ECHO_MSG} "found in ${PREFIX}/minimalist/sample."
	@${ECHO_MSG} "-------------------------------------------------------------------"

.include <bsd.port.mk>
