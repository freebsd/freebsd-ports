# New ports collection makefile for:	urchin5
# Date created:				September 8, 2003
# Whom:					Urchin Software
#
# $FreeBSD$
#

PORTNAME=	urchin
PORTVERSION=	5.501
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.urchin.com/pub/urchin5/
DISTNAME=	urchin5501_freebsd4x

MAINTAINER=	freebsd@urchin.com
COMMENT=	The most powerful web traffic analysis program available

ONLY_FOR_ARCHS=	i386
LICENSE=	commercial
RESTRICTED=	"Commercial software, also comes bundled with Apache-SSL"
NO_BUILD=	YES
NO_CDROM=	"Our installer must be run for proper permissions to be set"
NO_PACKAGE=	"Our installer must be run for proper permissions to be set"

BROKEN=		"Does not build with a read-only ports tree"

# Feel free to change this to the user you want Urchin 5 to
# run as and the files to be owned by (except root).  It's *strongly*
# advised to make this a non-privileged user.  The port can be changed
# later if desired.
USER=		nobody
GROUP=		nobody
PORT=		9999
INSTALLDIR=	${PREFIX}/urchin
QUIET=		-q
START_SERVERS=	yes

do-configure:
	${CP} ${FILESDIR}/install.sh ./work

do-install:
	@if test -f ${INSTALLDIR}/data/conf/uconf.uni; then \
		${ECHO_CMD} "The Urchin configuration files already exist,"; \
		${ECHO_CMD} "so I will attempt to do an upgrade instead of a new installation."; \
		${ECHO_CMD} ; \
	 	cd ./work; \
		${SH} ./install.sh ${QUIET} -d ${INSTALLDIR} -p ${PORT} -u ${USER} -g ${GROUP} -s ${START_SERVERS} -m; \
	else \
	 	cd ./work; \
		${SH} ./install.sh ${QUIET} -d ${INSTALLDIR} -p ${PORT} -u ${USER} -g ${GROUP} -s ${START_SERVERS} -n; \
	fi

post-install:
	${INSTALL_DATA} ${INSTALLDIR}/util/urchin_daemons ${PREFIX}/etc/rc.d/urchin5_daemons.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/urchin5_daemons.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/urchin5_daemons.sh startup file."; \
		${INSTALL_SCRIPT} ${INSTALLDIR}/util/urchin_daemons ${PREFIX}/etc/rc.d/urchin5_daemons.sh; \
	fi
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Thank you for installing Urchin 5!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Be sure to read the license agreement in ${INSTALLDIR}/doc/license.txt"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
