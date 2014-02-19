# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdrkit
PORTVERSION=	1.1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/ \
		http://debburn.alioth.debian.org/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Command-line CD/DVD writing suite

USES=		cmake iconv

CONFLICTS=	cdrtools-[0-9]* cjk-cdrtools-[0-9]* cdrtools-devel-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/include/AddSchilyBits.cmake \
	    ${WRKSRC}/3rd-party/dirsplit/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|fexecve|librols_fexecve|g' \
	    ${WRKSRC}/librols/fexec.c \
	    ${WRKSRC}/include/schily.h
	@${REINPLACE_CMD} -e 's|getdelim|wodim_getdelim|g' ${WRKSRC}/wodim/cue.c

.include <bsd.port.mk>
