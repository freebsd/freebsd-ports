# New ports collection makefile for:	aolserver
# Date created:		13 January 2000
# Whom:			Matthew Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	aolserver
PORTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	mab@red-bean.com
COMMENT=	A multithreaded web server with embedded TCL interpreter

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

INSTALL_TARGET=	install INST=${PREFIX}/${PORTNAME}

post-extract:
	${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

post-install:
# Headers
# nsd.h is needed for, e.g., building the Postgres driver
.for header in nsd/nsd.h
	 ${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/${PORTNAME}/include
.endfor
	 ${RM} ${PREFIX}/${PORTNAME}/include/*.orig

# Other documentation
	 ${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	 ${TAR} -C ${WRKSRC} -c -f - ChangeLog README | ${TAR} -C ${PREFIX}/share/doc/${PORTNAME} -x -f -
	 ${TAR} -C ${WRKSRC}/doc -c -f - . | ${TAR} -C ${PREFIX}/share/doc/${PORTNAME} -x -f -

# Permissions
	${CHOWN} nobody:nogroup ${PREFIX}/${PORTNAME}/servers/server1/modules/nslog
	${CHOWN} nobody:nogroup ${PREFIX}/${PORTNAME}/log

# Startup file
	@if [ ! -f ${PREFIX}/etc/rc.d/aolserver.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/aolserver.sh startup file."; \
		${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/aolserver.sh \
			>${PREFIX}/etc/rc.d/aolserver.sh ; \
		${CHMOD} 755 ${PREFIX}/etc/rc.d/aolserver.sh; \
	fi
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
