# ex:ts=8
# Ports collection makefile for:	intk-gconf
# Date created:			Mar 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	inti-gconf
PORTVERSION=	1.0.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	inti

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Inti binding for GConf, the GNOME Configuration System

LIB_DEPENDS=	inti-1.0.9:${PORTSDIR}/x11-toolkits/inti

USE_GNOME=	gconf2 gnomehack gnomeprefix
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	lib/libinti-gconf-1.0.so lib/libinti-gconf-1.0.so.6 \
		lib/inti-1.0/include/inti-gconf-config.h \
		libdata/pkgconfig/inti-gconf-1.0.pc

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/inti-gconf-config.h.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "include/inti-1.0/inti/inti-gconf.h" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/inti-1.0/inti/gconf -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/inti-1.0/inti/gconf" >> ${TMPPLIST}

.include <bsd.port.mk>
