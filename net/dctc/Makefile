# New ports collection makefile for:	Direct Connect Text Client
# Date created:				Thu Nov 22 00:19:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.83.8
CATEGORIES=	net
MASTER_SITES=	http://unixpages.org/distfiles/ \
		http://ac2i.tzo.com/dctc/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt \
		${PTHREAD_LIBS:S/"//g}"
CONFIGURE_ARGS=	--enable-manual-db-detect
MANCOMPRESSED=	no

MAN1=	dctc.1

DCTC_BINS=	dctc dctc_cmd
DOC_DIRS=	Documentation Documentation/DCextensions
DOC_FILES=      COPYING ChangeLog INSTALL README \
		KNOWN_BUGS TODO \
		Documentation/BerkeleyDB \
		Documentation/BerkeleyDB.nl \
		Documentation/DCextensions/p2p_capabilities \
		Documentation/DCextensions/p2p_capabilities.nl \
		Documentation/DCextensions/search_by_content \
		Documentation/DCextensions/search_by_content.nl \
		Documentation/GDL.nl \
		Documentation/GDL Documentation/VAR \
		Documentation/LS_cache Documentation/UNODE.nl \
		Documentation/LS_cache.nl \
		Documentation/VAR.nl \
		Documentation/UNODE Documentation/Vshare \
		Documentation/Vshare.nl \
		Documentation/commands \
		Documentation/commands.nl \
		Documentation/programs.nl \
		Documentation/programs.pl \
		Documentation/output.nl \
		Documentation/output Documentation/programs

post-extract:
	@${CP} ${FILESDIR}/lp_mutex.c ${WRKSRC}/src

post-patch:
.for file in ${DOC_FILES}
	@${PERL} -pi -e 's|(hublist)|dc_\1|' ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e 's/(CK?\()inet_ntoa(\))/\1shared_info\2/' ${WRKSRC}/src/*
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${PERL} -pi -e \
		's|<(db.h>)|<db4/\1|'
	@${PERL} -pi -e 's|(db)-|\1|g;s|db4.0|db4|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's|/usr/bin/env perl|${PERL}|' \
		${WRKSRC}/GDLjoiner
	@${REINPLACE_CMD} -E -e 's|^(dctc_SOURCES.+)$$|\1 lp_mutex.c|; \
		s|^(dctc_OBJECTS[^\\]+)(\\*)$$|\1 lp_mutex.o \2|' \
		${WRKSRC}/src/Makefile.in

pre-build:
	@${ECHO_CMD} '#ifndef MSG_NOSIGNAL' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '# define MSG_NOSIGNAL 0' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#endif' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#ifndef ENODATA' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '# define ENODATA ENOMSG' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#endif' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO_CMD} '#define HAVE_SYS_PARAM_H 1' >> ${CONFIGURE_WRKSRC}/config.h
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's! (autoconf|autoheader|automake|aclocal)$$! ${TRUE}!'

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
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/GDLjoiner \
		${PREFIX}/share/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/src/hublist ${PREFIX}/bin/dc_hublist
.for file in ${DCTC_BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
