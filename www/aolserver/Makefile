# New ports collection makefile for:	aolserver
# Date created:		13 January 2000
# Whom:			Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	aolserver
PORTVERSION=	3.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.aolserver.com/3.0/
DISTNAME=	aolserver3_0

MAINTAINER=	mab@red-bean.com

USE_GMAKE=	yes

INSTALL_TARGET=	install INST=${PREFIX}/aolserver

post-install:
# Headers
# nsd.h is needed for, e.g., building the Postgres driver
	${MKDIR} ${PREFIX}/include/aolserver
.for header in include/*.h nsd/nsd.h
	${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/aolserver
.endfor

# Libraries
	${INSTALL_DATA} ${WRKSRC}/nspd/libnspd.a ${PREFIX}/lib

# Other documentation
	${MKDIR} ${PREFIX}/share/doc/aolserver
	${TAR} -C ${WRKSRC} -c -f - ChangeLog LICENSE.txt README.txt doc | ${TAR} -C ${PREFIX}/share/doc/aolserver -x -f -

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
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
