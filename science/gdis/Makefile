# ex:ts=8
# Ports collection Makefile for:	gdis
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gdis
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display and manipulation of isolated molecules and periodic systems

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes

CFLAGS+=	-DINSTALL=\"\\\"${DATADIR}\\\"\"

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<sys/dir.h>|<dirent.h>|g ; \
		 s|struct direct|struct dirent|g'

do-configure:
	@${SED} 's|SRC.*=|SRCS=|g' < ${WRKSRC}/makefile.src > ${WRKSRC}/Makefile
	@${ECHO_CMD} 'PROG=gdis' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'CFLAGS+=`pkg-config --cflags gtk+-2.0 gthread-2.0 gtkglext-1.0`' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'LDADD=`pkg-config --libs gtk+-2.0 gthread-2.0 gtkglext-1.0`' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'PREFIX?=/usr/local' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'DESTDIR=$${PREFIX}' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'BINDIR=/bin' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} 'NOMAN=true' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} '.include <bsd.prog.mk>' >> ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdis ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gdis.elements ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
