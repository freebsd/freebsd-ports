# New ports collection makefile for:	Direct Connect Text Client
# Date created:				Thu Nov 22 00:19:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.67.0
CATEGORIES=	net
MASTER_SITES=	http://ac2i.tzo.com/dctc/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
DOC_DIRS=	Documentation Documentation/DCextensions
DOC_FILES=      COPYING ChangeLog INSTALL README \
		KNOWN_BUGS TODO \
		Documentation/DCextensions/p2p_capabilities \
		Documentation/DCextensions/search_by_content \
		Documentation/GDL Documentation/VAR \
		Documentation/commands \
		Documentation/output Documentation/programs

post-patch:
.for file in ${DOC_FILES}
	@${PERL} -pi -e 's|(hublist)|dc_\1|' ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e 's/(CK?\(std)(out\))/\1_\2/' ${WRKSRC}/src/*
	@${PERL} -pi -e 's/(CK?\()inet_ntoa(\))/\1shared_info\2/' ${WRKSRC}/src/*
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${PERL} -pi -e \
		's|include.+<linux/sem.h>|include <sys/ipc.h>\n#include <sys/sem.h>|'
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_CFLAGS} ${PTHREAD_LIBS}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#endif' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#include <errno.h>' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#ifndef ENODATA' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '# define ENODATA ENOMSG' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#endif' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#include <sys/param.h>' >> ${CONFIGURE_WRKSRC}/config.h

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for dir in ${DOC_DIRS}
	@${MKDIR} ${DOCSDIR}/${dir}
.endfor
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/${file}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/src/hublist ${PREFIX}/bin/dc_hublist
	@${INSTALL_PROGRAM} ${WRKSRC}/src/dctc ${PREFIX}/bin

.include <bsd.port.mk>
