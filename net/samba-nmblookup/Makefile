# New ports collection makefile for:	samba-nmblookup
# Date created:				Mon Dec  5 17:00:56 JST 2005
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-nmblookup

COMMENT=		NetBIOS Name lookup tool

CONFLICTS=		ja-samba-2.* ja-samba-3.* samba-2.* samba-3.*

SAMBA_PORT=		samba3
SAMBA_SUBPORT=		yes

.if ${SAMBA_PORT} != "samba3"
BROKEN=			"Does not build with samba-2 port"
.endif

MASTERDIR=		${.CURDIR}/../../net/${SAMBA_PORT}
PKGDIR=			${.CURDIR}

MAN1=			nmblookup.1
MAN5=			smb.conf.5
PLIST_FILES=		bin/nmblookup

# This is taken from SAMBA_PORT
WITHOUT_ADS=		yes

do-build:
	cd ${WRKSRC} && ${MAKE} include/proto.h
	cd ${WRKSRC} && ${MAKE} bin/nmblookup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nmblookup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../docs/manpages/nmblookup.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/../docs/manpages/smb.conf.5 ${MAN5PREFIX}/man/man5

.include "${MASTERDIR}/Makefile"
