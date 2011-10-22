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

CONFLICTS=		ja-samba-[23].* samba-[2-4].*

SAMBA_PORT=		samba36
SAMBA_SUBPORT=		yes

SAMBA_CONFIG=		smb-client.conf

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
FILESDIR=		${.CURDIR}/files
PKGDIR=			${.CURDIR}

WITHOUT_ADS=		yes

MAN1=			smbclient.1

PLIST_SUB+=		SAMBA_CONFDIR="${SAMBA_CONFDIR:S,^${PREFIX}/,,}" \
			SAMBA_CONFIG="${SAMBA_CONFIG}"

ALL_TARGET=		bin/smbclient

do-install:
	-@${MKDIR} ${SAMBA_CONFDIR}
	${INSTALL_DATA} ${FILESDIR}/smb-client.conf.sample ${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample
	@if [ ! -f "${SAMBA_CONFDIR}/${SAMBA_CONFIG}" ]; then \
	    ${CP} -p "${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample" "${SAMBA_CONFDIR}/${SAMBA_CONFIG}"; \
	fi
	-@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/smbclient ${PREFIX}/bin
	-@${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/smbclient.1 ${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
