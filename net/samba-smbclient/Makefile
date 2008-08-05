# New ports collection makefile for:	samba-smbclient
# Date created:				Mon Jul 28 12:43:50 BRT 2008
# Whom:					garga
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-smbclient

COMMENT=		Samba "ftp-like" client

CONFLICTS=		ja-samba-2.* ja-samba-3.* samba-2.* samba-3.*

SAMBA_CONFIG=		smb-client.conf
SAMBA_PORT?=		samba3
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
FILESDIR=		${.CURDIR}/files
PKGDIR=			${.CURDIR}

WITHOUT_ADS=		yes

MAN1=			smbclient.1
PLIST_FILES=		bin/smbclient \
			${SAMBA_CONFDIR:S,^${PREFIX}/,,}/${SAMBA_CONFIG}.sample

do-build:
	cd ${WRKSRC} && ${MAKE} include/proto.h
	cd ${WRKSRC} && ${MAKE} bin/smbclient

do-install:
	${INSTALL_DATA} ${FILESDIR}/smb-client.conf.sample ${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample
	@if [ ! -f "${SAMBA_CONFDIR}/${SAMBA_CONFIG}" ]; then \
	    ${CP} -p "${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample" "${SAMBA_CONFDIR}/${SAMBA_CONFIG}"; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/bin/smbclient ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/smbclient.1 ${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
