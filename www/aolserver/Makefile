# New ports collection makefile for:	aolserver
# Date created:		13 January 2000
# Whom:			Matthew Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	aolserver
PORTVERSION=	3.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.aolserver.com/aolserver/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	mab@red-bean.com

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

INSTALL_TARGET=	install INST=${PREFIX}/${PORTNAME}

post-extract:
	${MV} ${WRKSRC}/include/Makefile.global ${WRKSRC}/include/Makefile.global.orig
	${SED} s/tcl83/tcl8.3/ ${WRKSRC}/include/Makefile.global.orig > ${WRKSRC}/include/Makefile.global
	${RM} ${WRKSRC}/include/Makefile.global.orig
	find ${WRKSRC} -name CVS | xargs ${RM} -rf

post-install:
# Headers
# nsd.h is needed for, e.g., building the Postgres driver
.for header in nsd/nsd.h
	 ${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/${PORTNAME}/include
.endfor

# Other documentation
	 ${MKDIR} ${PREFIX}/share/doc/aolserver
	 ${TAR} -C ${WRKSRC} -c -f - ChangeLog README | ${TAR} -C ${PREFIX}/share/doc/aolserver -x -f -
	 ${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${PREFIX}/share/doc/aolserver -x -f -

# Permissions
	${CHOWN} nobody:nogroup ${PREFIX}/aolserver/servers/server1/modules/nslog
	${CHOWN} nobody:nogroup ${PREFIX}/aolserver/log

# Startup file
	@if [ ! -f ${PREFIX}/etc/rc.d/aolserver.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/aolserver.sh startup file."; \
		${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/aolserver.sh \
			>${PREFIX}/etc/rc.d/aolserver.sh ; \
		${CHMOD} 755 ${PREFIX}/etc/rc.d/aolserver.sh; \
	fi
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
