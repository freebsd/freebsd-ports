# New ports collection makefile for:	xanim
# Version required:     2.70.6.4
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.14 1998/09/14 20:37:01 markm Exp $
#

DISTNAME=       xanim27070
PKGNAME=        xanim-2.70.7.0
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/ \
		ftp://xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

MAINTAINER=	ports@FreeBSD.ORG

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
USE_IMAKE=	yes
MAN1=		xanim.1
MANCOMPRESSED=	yes

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  ${CP} ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done
	${CP} ${WRKSRC}/docs/xanim.man ${WRKSRC}

MAKE_ENV+=	XA_IV32_DEF=-DXA_INDEO \
		XA_CVID_DEF=-DXA_CINEPAK \
		XA_CYUV_DEF=-DXA_CYUV

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} != elf
EXTRA_FILES=    xa2.0_cvid_netbsd386.o.Z xa2.0_iv32_netbsd386.o.Z \
		xa1.0_cyuv_netbsd386.o.Z
MAKE_ENV+=	XA_IV32_LIB=xa2.0_cvid_netbsd386.o \
		XA_CVID_LIB=xa2.0_iv32_netbsd386.o \
		XA_CYUV_LIB=xa1.0_cyuv_netbsd386.o
.else
EXTRA_FILES=    xa2.0_cvid_linuxELF.o.Z xa2.0_iv32_linuxELF.o.Z \
		xa1.0_cyuv_linuxELF.o.Z
MAKE_ENV+=	XA_IV32_LIB=xa2.0_cvid_linuxELF.o \
		XA_CVID_LIB=xa2.0_iv32_linuxELF.o \
		XA_CYUV_LIB=xa1.0_cyuv_linuxELF.o
.endif
