# New ports collection makefile for:	aolserver
# Date created:		13 January 2000
# Whom:			Matthew Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	aolserver
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.aolserver.com/server/aolserver3_2/
DISTNAME=	aolserver3_2-source

MAINTAINER=	mab@red-bean.com

WRKSRC=		${WRKDIR}/aolserver3_2

USE_GMAKE=	yes

INSTALL_TARGET=	install INST=${PREFIX}/aolserver

post-extract:
	find ${WRKSRC} -name CVS | xargs ${RM} -rf

post-install:
# Headers
# nsd.h is needed for, e.g., building the Postgres driver
.for header in nsd/nsd.h
	 ${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/aolserver/include
.endfor

# Other documentation
	 ${MKDIR} ${PREFIX}/share/doc/aolserver
	 ${TAR} -C ${WRKSRC} -c -f - ChangeLog README | ${TAR} -C ${PREFIX}/share/doc/aolserver -x -f -
	 ${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${PREFIX}/share/doc/aolserver -x -f -

# Permissions
	${CHOWN} nobody.nogroup ${PREFIX}/aolserver/servers/server1/modules/nslog
	${CHOWN} nobody.nogroup ${PREFIX}/aolserver/log

# Startup file
	@if [ ! -f ${PREFIX}/etc/rc.d/aolserver.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/aolserver.sh startup file."; \
		${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/aolserver.sh \
			>${PREFIX}/etc/rc.d/aolserver.sh ; \
		${CHMOD} 755 ${PREFIX}/etc/rc.d/aolserver.sh; \
	fi
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
