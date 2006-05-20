# New ports collection makefile for:	dar
# Date created:				3 January 2004
# Whom:					Edson Brandi <ebrandi@fugspbr.org>
#
# $FreeBSD$
#

PORTNAME=	dar
PORTVERSION=	2.3.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	ebrandi@fugspbr.org
COMMENT=	A full featured command-line backup tool, aimed for disks

USE_AUTOTOOLS=	libtool:15

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --disable-build-html --datadir=${DATADIR}

CPPFLAGS=	-DHAVE_DECL_GETOPT=0

MAN1=		dar.1 dar_cp.1 dar_manager.1 dar_slave.1 dar_xform.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-libdar-integers.hpp
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-libintl-prefix=${PREFIX}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's,(_nl_expand_alias) \(0\),\1 (),g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.dtd *.txt *.jpg [CR]* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/samples
	cd ${WRKSRC}/doc/samples && ${INSTALL_DATA} [JR]* [a-z]* ${DOCSDIR}/samples
	@${MKDIR} ${DOCSDIR}/mini-howto
	cd ${WRKSRC}/doc/mini-howto && ${INSTALL_DATA} *.html README ${DOCSDIR}/mini-howto
.endif

.include <bsd.port.mk>
