# Created by: garga
# $FreeBSD$

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-smbclient

COMMENT=		Samba "ftp-like" client

CONFLICTS=		ja-samba-[23].* samba-[2-4].*

SAMBA_PORT=		samba36
SAMBA_SUBPORT=		yes

SAMBA_CONFIG=		smb-client.conf

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
FILESDIR=		${.CURDIR}/files
PKGDIR=			${.CURDIR}

WITHOUT_ADS=		yes

PLIST_SUB+=		SAMBA_CONFDIR="${SAMBA_CONFDIR:S,^${PREFIX}/,,}" \
			SAMBA_CONFIG="${SAMBA_CONFIG}"

ALL_TARGET=		bin/smbclient

do-install:
	-@${MKDIR} ${STAGEDIR}${SAMBA_CONFDIR}
	${INSTALL_DATA} ${FILESDIR}/smb-client.conf.sample ${STAGEDIR}${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample
	-@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/smbclient ${STAGEDIR}${PREFIX}/bin
	-@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/smbclient.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
