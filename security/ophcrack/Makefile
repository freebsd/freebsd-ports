# New ports collection makefile for:	ophcrack
# Date created:				14 Mar 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ophcrack
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bkhive-${TOOLS_VER}${EXTRACT_SUFX} \
		samdump2-${TOOLS_VER}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Windows password cracker based on rainbow tables

USE_GNOME=	gtk20
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PORTDOCS=	*
MAN1=		bkhive.1 samdump2.1

TOOLS_VER=	1.1.1

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/d' ${WRKSRC}/${CONFIGURE_SCRIPT}
# Do not install any Linux binaries: we build and install native ones;
# mute their banner as well in favor of our nice pkg-message
	@${REINPLACE_CMD} -e 's/ install-exec-local// ; 605,617d' \
		${WRKSRC}/Makefile.in
# Hint the tools about correct endianness
	@${REINPLACE_CMD} -e '22s,^$$,#include <sys/endian.h>,' \
		${WRKDIR}/bkhive-${TOOLS_VER}/bkhive.c
	@${REINPLACE_CMD} -e '26s,^$$,#include <sys/endian.h>,' \
		${WRKDIR}/bkhive-${TOOLS_VER}/hive.c
	@${REINPLACE_CMD} -e '27s,^$$,#include <sys/endian.h>,' \
		${WRKDIR}/samdump2-${TOOLS_VER}/samdump2.c
# FreeBSD does not have <byteswap.h>
	@${REINPLACE_CMD} -e '/byteswap\.h/d' \
		${WRKDIR}/bkhive-${TOOLS_VER}/bkhive.c \
		${WRKDIR}/bkhive-${TOOLS_VER}/hive.c \
		${WRKDIR}/samdump2-${TOOLS_VER}/samdump2.c
# And our swap function names are prettier
	@${REINPLACE_CMD} -E 's,__bswap_([[:digit:]]+),bswap\1,' \
		${WRKDIR}/bkhive-${TOOLS_VER}/hive.c \
		${WRKDIR}/samdump2-${TOOLS_VER}/samdump2.c
# Link to file instead of patching identical copy
	@${LN} -sf ../bkhive-${TOOLS_VER}/hive.c \
		${WRKDIR}/samdump2-${TOOLS_VER}/hive.c

post-build:
# Build auxiliary tools (useful: e.g., samdump2 is called at runtime)
	(cd ${WRKDIR}/bkhive-${TOOLS_VER} && ${CC} ${CFLAGS} -o bkhive \
		hive.c bkhive.c)
	(cd ${WRKDIR}/samdump2-${TOOLS_VER} && ${CC} ${CFLAGS} -o samdump2 \
		hive.c samdump2.c -lssl)

post-install:
# Install auxiliary tools and their manpages
	${INSTALL_PROGRAM} ${WRKDIR}/bkhive-${TOOLS_VER}/bkhive \
		${WRKDIR}/samdump2-${TOOLS_VER}/samdump2 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/bkhive-${TOOLS_VER}/bkhive.1 \
		${WRKDIR}/samdump2-${TOOLS_VER}/samdump2.1 \
			${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
