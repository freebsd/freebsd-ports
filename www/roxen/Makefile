# New ports collection makefile for:	Roxen Challenger
# Version required:	1.3.111-0.6-40bit
# Date created:		26 February 1999
# Whom:			Kai Voigt (k@123.org)
#
# $FreeBSD$
#

DISTNAME=	roxen_1.3.111-0.6-40bit
PKGNAME=	roxen-1.3.111
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.roxen.com/roxen/source/

MAINTAINER=	k@123.org

WRKSRC=		${WRKDIR}/roxen_1.3.111
GNU_CONFIGURE=	yes

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/roxen.sh

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/roxen.sh > \
	  ${WRKDIR}/roxen.sh

do-configure:
	@(cd ${WRKSRC}; \
	  ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
	  ${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; \
	  ${INSTALL_SCRIPT} ${FILESDIR}/roxen.sh ${STARTUP_SCRIPT}; \
	fi
	@${ECHO_MSG} "Installation of Roxen Challenger finished!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Now perform the following steps to initialize"
	@${ECHO_MSG} "the webserver."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "# cd ${PREFIX}/roxen/server/"
	@${ECHO_MSG} "# ./install"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Then follow the instructions.  For further"
	@${ECHO_MSG} "documentation read http://roxen.com/documentation/"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
