# New ports collection makefile for:   gtkada-gcc
# Date Created:			24 Dec 2006
# Whom:				Petr Holub <hopet@ics.muni.cz>
#
# $FreeBSD$
#

PORTNAME=	gtkada
PORTVERSION=	2.8.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnuada
PKGNAMESUFFIX=	-gcc
DISTNAME=	gnat-gcc-gtkada-4.1.1_2.8.1-r6.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	Gtk2 binding for lang/gnat-gcc41 port of GNAT Ada compiler

BUILD_DEPENDS=	${LOCALBASE}/bin/gcc41/gcc41:${PORTSDIR}/lang/gnat-gcc41

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

WRKSRC=		${WRKDIR}/GtkAda-2_8_1

CONFLICTS=	gtkada-[0-9]* \
		gtkada-devel-[0-9]*

CC=		${LOCALBASE}/bin/gcc41/gcc41
CONFIGURE_ENV+=	PATH=${LOCALBASE}/bin/gcc41:${PATH} CC=${CC}
MAKE_ENV+=	PATH=${LOCALBASE}/bin/gcc41:${PATH}
CONFIGURE_ARGS=	--with-GL=GL

USE_GL=		gl glu
USE_GNOME=	gnomehack gtk20 libglade2
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

#EXAMPLESDIR=	${DATADIR}/examples

do-extract:
	if [ ! -d ${WRKDIR} ]; then \
		${MKDIR} ${WRKDIR}; \
	fi
	( cd ${WRKDIR} && \
	rpm2cpio.pl <${DISTDIR}/gnat-gcc-gtkada-4.1.1_2.8.1-r6.src.rpm | ${CPIO} -i GtkAda-2_8_1.tar.bz2 && \
	tar jxf GtkAda-2_8_1.tar.bz2 )

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/projects/Makefile

.include <bsd.port.mk>
