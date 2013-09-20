# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-nmblookup

COMMENT=		NetBIOS Name lookup tool

CONFLICTS=		ja-samba-[23].* samba-[2-4].*

SAMBA_PORT=		samba36
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

MAN1=			nmblookup.1
MAN5=			smb.conf.5
PLIST_FILES=		bin/nmblookup

WITHOUT_ADS=		yes

ALL_TARGET=		bin/nmblookup

NO_STAGE=	yes
do-install:
	-@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nmblookup ${PREFIX}/bin
	-@${MKDIR} ${MAN1PREFIX}/man/man1 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/nmblookup.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/smb.conf.5 ${MAN5PREFIX}/man/man5

.include "${MASTERDIR}/Makefile"
